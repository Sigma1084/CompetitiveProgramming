import qrcode

# Set the colors corresponding to 0 and 1 respectively, the default is black and white
qr = qrcode.QRCode(version=None, box_size=1, border=0,
                   error_correction=qrcode.constants.ERROR_CORRECT_L)

# The string to generate (can be any text)
data = "12"

# Add the data of the QR code to be generated to the qr object
qr.add_data(data)

# Generate a QR code and save it as a PNG file
img = qr.make_image(fill_color="black", back_color="white")
img.save("qr_code.png")

# Convert QR code data to 01 string
qr_str = qr.get_matrix()
qr_str = '\n'.join([''.join([('1' if cell else '0') for cell in row]) for row in qr_str])
print(qr_str)