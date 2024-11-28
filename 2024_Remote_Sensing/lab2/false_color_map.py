# Cleanup
project = QgsProject.instance()
layer_ids = list(project.mapLayers().keys())
for layer_id in layer_ids:
    project.removeMapLayer(layer_id)

# Loading B10 Layer
path_st_b10 = "/home/huaqo/dev/courses/2024_Remote_Sensing/lab2/false_color/false_color.tif"
st_b10_layer = QgsRasterLayer(path_st_b10, "False Color Composite")
if not st_b10_layer.isValid():
    print("st_b10 layer failed to load!")
else:
    QgsProject.instance().addMapLayer(st_b10_layer)
    print("st_b10 Layer loaded!")

# Styling Layer
st_b10_style_path = '/home/huaqo/dev/courses/2024_Remote_Sensing/styles/false_color.qml'
if not st_b10_layer.loadNamedStyle(st_b10_style_path):
    print("Failed to load st_b10 style!")
else:
    print("st_b10 style loaded!")

# Load layout
layout = QgsPrintLayout(project)
layout.initializeDefaults()

# Map
map_item = QgsLayoutItemMap(layout)
map_item.attemptMove(QgsLayoutPoint(20, 30, QgsUnitTypes.LayoutMillimeters))  # Added space between top and map
map_item.attemptResize(QgsLayoutSize(200, 150, QgsUnitTypes.LayoutMillimeters))  # Reduced height for better spacing
map_item.zoomToExtent(st_b10_layer.extent())
layout.addLayoutItem(map_item)

# Add Coordinate Grid
grid = map_item.grid()
grid.setEnabled(True)
grid.setIntervalX(100000)  # Set interval for grid lines in map units
grid.setIntervalY(100000)
grid.setAnnotationEnabled(True)
grid.setAnnotationPrecision(0)  # Set annotation precision for grid labels
grid.setFrameStyle(QgsLayoutItemMapGrid.Zebra)  # Optional grid style

# Label
title_label = QgsLayoutItemLabel(layout)
title_label.setText("False Color Composite - Lab 2")
title_label.setFont(QFont("Arial", 16))
title_label.setHAlign(Qt.AlignCenter)
title_label.attemptMove(QgsLayoutPoint(105, 10, QgsUnitTypes.LayoutMillimeters))
title_label.adjustSizeToText()
layout.addLayoutItem(title_label)

# Legend
legend_item = QgsLayoutItemLegend(layout)
legend_item.setLinkedMap(map_item)
legend_item.setTitle("Legend")
legend_item.setFrameEnabled(True)
legend_item.attemptMove(QgsLayoutPoint(245, 30, QgsUnitTypes.LayoutMillimeters))  # Adjusted for better alignment and spacing
layout.addLayoutItem(legend_item)

# Scalebar
scalebar_item = QgsLayoutItemScaleBar(layout)
scalebar_item.setStyle('Single Box')  # Change to 'Single Box' or 'Double Box' for a proper scalebar
scalebar_item.setLinkedMap(map_item)
scalebar_item.setUnitLabel('m')  # Add unit label to make it informative
scalebar_item.setNumberOfSegments(4)  # Specify the number of segments in the scalebar
scalebar_item.setNumberOfSegmentsLeft(0)  # Segments to the left of zero (if any)
scalebar_item.setUnitsPerSegment(50000)  # Set distance per segment in map units
scalebar_item.setFont(QFont('Arial', 10))  # Set font size for better readability
scalebar_item.setHeight(5)  # Set the height of the scalebar
scalebar_item.applyDefaultSize()
scalebar_item.attemptMove(QgsLayoutPoint(20, 190, QgsUnitTypes.LayoutMillimeters))  # Moved below the map for better organization
layout.addLayoutItem(scalebar_item)

# North Arrow
north_arrow_item = QgsLayoutItemPicture(layout)
north_arrow_item.setPicturePath('/home/huaqo/dev/courses/2024_Remote_Sensing/styles/north_arrow.svg')
if not north_arrow_item.picturePath():
    print("North arrow image failed to load!")
north_arrow_item.setReferencePoint(QgsLayoutItemPicture.UpperLeft)
north_arrow_item.attemptMove(QgsLayoutPoint(30, 40, QgsUnitTypes.LayoutMillimeters))  # Adjusted placement for better visibility
north_arrow_item.attemptResize(QgsLayoutSize(15, 15, QgsUnitTypes.LayoutMillimeters))  # Increased size for better visibility
layout.addLayoutItem(north_arrow_item)

# Author
info_label = QgsLayoutItemLabel(layout)
info_label.setText("Author: Joaquin Gottlebe")
info_label.setFont(QFont("Arial", 12))
info_label.setHAlign(Qt.AlignLeft)
info_label.attemptMove(QgsLayoutPoint(245, 100, QgsUnitTypes.LayoutMillimeters))
info_label.adjustSizeToText()
layout.addLayoutItem(info_label)

# Author
info_label = QgsLayoutItemLabel(layout)
info_label.setText("Date: 16.11.2025")
info_label.setFont(QFont("Arial", 12))
info_label.setHAlign(Qt.AlignLeft)
info_label.attemptMove(QgsLayoutPoint(245, 110, QgsUnitTypes.LayoutMillimeters))
info_label.adjustSizeToText()
layout.addLayoutItem(info_label)

# Coordinate System
info_label = QgsLayoutItemLabel(layout)
info_label.setText("CRS: EPSG 32633")
info_label.setFont(QFont("Arial", 12))
info_label.setHAlign(Qt.AlignLeft)
info_label.attemptMove(QgsLayoutPoint(245, 120, QgsUnitTypes.LayoutMillimeters))
info_label.adjustSizeToText()
layout.addLayoutItem(info_label)


# Export
export_path = "/home/huaqo/dev/courses/2024_Remote_Sensing/lab2/maps/false_color.png"
exporter = QgsLayoutExporter(layout)
export_result = exporter.exportToImage(export_path, QgsLayoutExporter.ImageExportSettings())
if export_result != QgsLayoutExporter.Success:
    print("Failed to export map!")
else:
    print("Map exported to:", export_path)
