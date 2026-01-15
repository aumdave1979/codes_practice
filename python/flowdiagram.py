# Generating three diagrams for the Helmet-On Safety System:
# 1) Block diagram
# 2) Wiring schematic (simplified, conceptual)
# 3) Flowchart of runtime logic
#
# The images will be saved to /mnt/data and displayed in the notebook output.

from PIL import Image, ImageDraw, ImageFont
import matplotlib.pyplot as plt
import os

# Ensure output directory exists
out_dir = "/mnt/data"
os.makedirs(out_dir, exist_ok=True)

# Helper to save and display images using matplotlib
def save_and_show(img, filename):
    path = os.path.join(out_dir, filename)
    img.save(path)
    # Display using matplotlib
    fig, ax = plt.subplots(figsize=(10,6))
    ax.imshow(img)
    ax.axis('off')
    plt.show()
    return path

# Common font (fallback)
try:
    font = ImageFont.truetype("DejaVuSans.ttf", 14)
except:
    font = ImageFont.load_default()

# 1) Block diagram
w, h = 1200, 600
img = Image.new("RGB", (w,h), "white")
d = ImageDraw.Draw(img)

# Boxes positions
boxes = {
    "Rider / Helmet": (50, 60, 300, 160),
    "Camera\n(RPi Cam 3)": (350, 60, 600, 160),
    "Raspberry Pi\n(Core Logic)": (700, 50, 980, 170),
    "Relay\n(Ignition Kill)": (700, 220, 980, 320),
    "Buzzer / Alerts": (350, 220, 600, 320),
    "Optional\nGPS / GSM": (350, 380, 600, 480),
    "Bike\nIgnition / Engine": (50, 380, 300, 480)
}

for k, (x1,y1,x2,y2) in boxes.items():
    d.rectangle([x1,y1,x2,y2], outline="black", width=2)
    d.multiline_text((x1+10,y1+10), k, font=font, spacing=4)

# Arrows
def arrow(p1, p2):
    d.line([p1, p2], fill="black", width=2)
    # simple arrowhead
    ax, ay = p2
    bx, by = p1
    # compute direction
    dx = bx - ax
    dy = by - ay
    if dx==0 and dy==0:
        return
    # normalize
    import math
    L = math.hypot(dx, dy)
    ux, uy = dx/L, dy/L
    # two points for arrowhead
    left = (ax + ux*10 - uy*7, ay + uy*10 + ux*7)
    right = (ax + ux*10 + uy*7, ay + uy*10 - ux*7)
    d.polygon([p2, left, right], fill="black")

arrow((300,110),(350,110))  # rider -> camera
arrow((600,110),(700,110))  # camera -> RPi
arrow((840,170),(840,220))  # RPi -> Relay
arrow((600,270),(700,270))  # buzzer <- RPi
arrow((200,430),(300,430))  # bike ignition -> relay
arrow((450,430),(450,380))  # GPS -> RPi (upwards)
arrow((550,170),(700,150))  # buzzer -> RPi (signal)

# Titles
d.text((10,10),"Block Diagram: Helmet-On Safety System", font=font)

block_path = save_and_show(img, "helmet_block_diagram.png")

# 2) Wiring schematic (conceptual)
w, h = 1200, 800
img2 = Image.new("RGB", (w,h), "white")
d2 = ImageDraw.Draw(img2)
d2.text((10,10),"Wiring Schematic (Conceptual)", font=font)

# Draw battery and DC-DC
d2.rectangle([50,60,220,120], outline="black")
d2.text((60,70),"Bike Battery\n(12V)", font=font)
d2.rectangle([260,60,420,120], outline="black")
d2.text((270,70),"DC-DC Buck\n(12V -> 5V)", font=font)
d2.line([(220,90),(260,90)], fill="black", width=2)
d2.line([(420,90),(540,90)], fill="black", width=2)

# Raspberry Pi box
d2.rectangle([540,40,840,180], outline="black", width=2)
d2.text((560,50),"Raspberry Pi\n(5V Supply)", font=font)
d2.text((560,95),"GPIO17 -> Relay IN\nGPIO18 -> Buzzer\nCSI -> Camera\nGND common", font=font)

# Camera
d2.rectangle([100,180,380,260], outline="black")
d2.text((120,190),"RPi Cam 3\n(CSI Ribbon)", font=font)
d2.line([(300,260),(600,140)], fill="black", width=2)  # to RPi

# Relay and ignition
d2.rectangle([540,220,840,320], outline="black")
d2.text((560,230),"Relay Module\n(12V coil or 5V opto)\nNC/NO contacts", font=font)
# ignition box
d2.rectangle([50,320,220,420], outline="black")
d2.text((60,330),"Ignition Coil\n/Ignition Switch", font=font)
# relay contact lines
d2.line([(840,270),(880,270)], fill="black", width=2)
d2.line([(880,270),(980,270)], fill="black", width=2)
d2.line([(980,270),(980,370)], fill="black", width=2)
d2.line([(980,370),(220,370)], fill="black", width=2)
d2.line([(220,370),(220,330)], fill="black", width=2)

# buzzer
d2.rectangle([540,360,680,420], outline="black")
d2.text((550,370),"Buzzer", font=font)
d2.line([(700,390),(780,390)], fill="black", width=2)
d2.text((790,382),"-> Sound", font=font)

# Ground and common references
d2.text((560,440),"GND common to Pi, Relay, Buzzer", font=font)

# Notes
d2.text((50,460),"Notes:", font=font)
notes = [
    "1. Use DC-DC buck to supply stable 5V to Raspberry Pi from bike battery.",
    "2. Use relay in series with ignition kill wire. Configure NO/NC per bike wiring.",
    "3. Ensure proper flyback diode or opto-isolation for relay coil.",
    "4. Keep common ground between Pi and relay module.",
    "5. For safety, prefer an ignition-interrupt that allows safe pull-over (not abrupt cut while moving)."
]
y = 480
for n in notes:
    d2.text((60,y), n, font=font)
    y += 20

wire_path = save_and_show(img2, "helmet_wiring_schematic.png")

# 3) Flowchart
w, h = 1200, 1200
img3 = Image.new("RGB", (w,h), "white")
d3 = ImageDraw.Draw(img3)
d3.text((10,10),"Runtime Flowchart: Helmet-On Safety System", font=font)

# Helper to draw rounded rectangles and arrows
def round_rect(box, r=10):
    x1,y1,x2,y2 = box
    d3.rounded_rectangle([x1,y1,x2,y2], radius=r, outline="black", width=2)

def arrow_to(p1, p2):
    d3.line([p1,p2], fill="black", width=2)
    ax, ay = p2
    bx, by = p1
    import math
    dx = bx - ax
    dy = by - ay
    L = math.hypot(dx, dy) or 1
    ux, uy = dx/L, dy/L
    left = (ax + ux*8 - uy*6, ay + uy*8 + ux*6)
    right = (ax + ux*8 + uy*6, ay + uy*8 - ux*6)
    d3.polygon([p2, left, right], fill="black")

# Boxes positions
round_rect((350,70,850,140)); d3.text((420,90),"Start: Bike Ignition ON\n(RPi boots, camera init)", font=font)
round_rect((350,180,850,260)); d3.text((420,200),"Pre-Start Helmet Check\nCapture frame -> detect helmet", font=font)
round_rect((150,320,420,400)); d3.text((170,340),"Helmet Detected?", font=font)
round_rect((630,320,900,400)); d3.text((660,340),"Helmet NOT detected\nBlock ignition\nPlay warning", font=font)
round_rect((150,460,420,540)); d3.text((180,480),"Allow Start\nClose relay\nEngine allowed", font=font)
round_rect((630,460,900,540)); d3.text((650,480),"Wait 5 seconds\nRe-check\nIf still no helmet start  timer for enforcement", font=font)
round_rect((350,620,850,700)); d3.text((420,640),"In-Ride Continuous Monitoring\nHelmet presence + Hand detection\nIf violation -> warn -> start 5-min timer", font=font)
round_rect((350,760,850,840)); d3.text((420,780),"Violation persists 5 minutes?\nYes -> Open relay -> Safe shutdown\nNo -> Resume monitoring", font=font)
round_rect((350,900,850,980)); d3.text((520,920),"End / Normal Operation", font=font)

# Arrows connections
arrow_to((600,140),(600,180))
arrow_to((600,260),(300,320))
arrow_to((600,260),(750,320))
arrow_to((300,400),(300,460))
arrow_to((750,400),(750,460))
arrow_to((300,540),(600,620))
arrow_to((750,540),(600,620))
arrow_to((600,700),(600,760))
arrow_to((600,840),(600,900))

# Small decision arrows for Yes/No
d3.text((320,420),"Yes", font=font)
d3.text((720,420),"No", font=font)

flow_path = save_and_show(img3, "helmet_flowchart.png")

# Print saved file paths
paths = {
    "block_diagram": block_path,
    "wiring_schematic": wire_path,
    "flowchart": flow_path
}

paths

os.remove()
