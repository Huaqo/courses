// Detailed information: https://docs.google.com/document/d/1mNIRB90jwLuASO1JYas1kuOXCLbOoy1Z4NlV1qIXM10/edit

var imageCollection = ee.ImageCollection("LANDSAT/LC08/C02/T1_L2");
    
var roi = 
    ee.Geometry.Polygon(
        [[[120.34892531309845, 43.64119426062719],
          [120.34892531309845, 43.618332108842225],
          [120.39218398009064, 43.618332108842225],
          [120.39218398009064, 43.64119426062719]]], null, false);

Map.centerObject(roi, 12)


var l8sr = imageCollection
  .filterBounds(roi);

// This field contains UNIX time in milliseconds.
var timeField = 'system:time_start';

function maskL8sr(image) {
  // Bit 0 - Fill
  // Bit 1 - Dilated Cloud
  // Bit 2 - Cirrus
  // Bit 3 - Cloud
  // Bit 4 - Cloud Shadow
  var qa = image.select('QA_PIXEL')
  
  var cloud = qa.bitwiseAnd(1 << 1)
          .or(qa.bitwiseAnd(1 << 2))
          .or(qa.bitwiseAnd(1 << 3))
          .or(qa.bitwiseAnd(1 << 4))


  // The flags should equal zero, indicating clear conditions.
  var mask = cloud.eq(0);
      //var ndwiMasked = ndwi.updateMask(ndwi.gte(0.4)); 
  // Apply the scaling factors to the appropriate bands.
  var opticalBands = image.select('SR_B.').multiply(0.0000275).add(-0.2);

  // Replace the original bands with the scaled ones and apply the masks.
  return image.addBands(opticalBands, null, true)
      .updateMask(mask)
      .copyProperties(image, ['system:time_start']);
}

// Use this function to add variables for NDVI, time and a constant
// to Landsat 8 imagery.
var addVariables = function(image) {
  // Compute time in fractional years since the epoch.
  var date = ee.Date(image.get(timeField));
  var years = date.difference(ee.Date('1970-01-01'), 'year');
  // Return the image with the added bands.
  return image
    // Add an NDVI band.
    .addBands(image.normalizedDifference(['SR_B5', 'SR_B4']).rename('NDVI'))
    // Add a time band.
    .addBands(ee.Image(years).rename('t'))
    .float()
    // Add a constant band.
    .addBands(ee.Image.constant(1));
};

// Remove clouds, add variables and filter to the area of interest.
var filteredLandsat = l8sr
  .filterBounds(roi)
  .filter(ee.Filter.calendarRange(8,8, 'month'))
  .map(maskL8sr)
  .map(addVariables);


// Plot a time series of NDVI at a single location.
var l8Chart = ui.Chart.image.series(filteredLandsat.select('NDVI'), roi)
    .setChartType('ScatterChart')
    .setOptions({
      title: 'Landsat 8 NDVI time series at ROI',
      trendlines: {0: {
        color: 'CC0000'
      }},
      lineWidth: 1,
      pointSize: 3,
    });
print(l8Chart);

// Display the overall mean NDVI of the time series
Map.addLayer(filteredLandsat.select('NDVI').first(), {min: 0, max: 1}, "Mean NDVI")


// List of the independent variable names
var independents = ee.List(['constant', 't']);

// Name of the dependent variable.
var dependent = ee.String('NDVI');

// Compute a linear trend.  This will have two bands: 'residuals' and 
// a 2x1 band called coefficients (columns are for dependent variables).
var trend = filteredLandsat.select(independents.add(dependent))
    .reduce(ee.Reducer.linearRegression(independents.length(), 1));
Map.addLayer(trend, {}, 'trend array image');

// Flatten the coefficients into a 2-band image
var coefficients = trend.select('coefficients')
  .arrayProject([0])
  .arrayFlatten([independents]);

print(coefficients)


Map.addLayer(coefficients.select('t'), {min: -0.05, max: 0.05}, "gain b")
Map.addLayer(coefficients.select('constant'),{min: -0.1, max: 1}, "offset a")

