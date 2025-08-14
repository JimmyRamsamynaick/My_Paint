#!/usr/bin/env python3
from PIL import Image, ImageDraw

# Create a simple test image
width, height = 200, 150
image = Image.new('RGB', (width, height), 'lightblue')
draw = ImageDraw.Draw(image)

# Draw a red circle
draw.ellipse([50, 25, 150, 125], fill='red')

# Save the image
image.save('test_image.png')
print('Test image created: test_image.png')