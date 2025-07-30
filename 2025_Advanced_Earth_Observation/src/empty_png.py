from PIL import Image


def empty_png(path):

    # Set the size of the image (width, height)
    width = 800
    height = 600

    # Create a new transparent image (RGBA mode)
    transparent_image = Image.new("RGBA", (width, height), (0, 0, 0, 0))

    # Save the image as PNG
    transparent_image.save(path)

    print("Transparent PNG created successfully!")
