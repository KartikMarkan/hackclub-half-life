
# NovaSense!!!
NovaSense is my first ever PCB design project that I have ever made! I was so exicted to make this project, and I can't wait to solder it! This ReadMe will explain the whole process I went through: 


## Hardware/Connections: 
### Components
- **Microcontroller**: Arduino-compatible board (e.g., NodeMCU, D1 Mini)
- **Display**: SSD1306 128x64 OLED screen (I2C interface)
- **Sensor**: DHT11 Temperature/Humidity sensor
- **Buttons**: 2x momentary push buttons (SW1, SW2)
- **LED**: Status indicator LED

### Pin Configuration
| Component | Pin |
|-----------|-----|
| Left Button (SW1) | D2 |
| Right Button (SW2) | D3 |
| LED | D6 |
| DHT11 Sensor | D1 |
| OLED SDA | D5 |
| OLED SCL | D4 |

### I2C Address
- OLED Display: `0x3C`

## Software Stack

- **Language**: C++ (Arduino)
- **Display Library**: Adafruit GFX + Adafruit SSD1306
- **Sensor Library**: Adafruit DHT
- **Communication**: I2C (Wire.h)
- **Baud Rate**: 115200 (Serial debugging)

## Project Structure


## MY JOURNAL:
### 
Started My First PCB Project!!!!

I started off by following the Starbie PCB design.
I did this by first downloading the KiCad software on my computer and connecting it to GitHub. After that, I watched 5 minutes of a 30 min youtube (its called Beginner's Guide to PCB Design in 30 Minutes by Tinkering Techie). I followed along to the instructions, and it took me ten whole minutes(lol): 

My diagrm from the Youtube Tutorial: 

![This is first image](Project1/images/Hackrtt.png)


After watching the video, and checking voer everything, I decided to move on to the Starbie Tutorial from Half Life( Note: I am only using the tutorial to leanr before starting my actual PCB project). 

I started with the first step of getting the Seeed Studio XIAO ESP32-C3 connected to the other components, like the DHT11 moudel. After connecting everything based on the guide, I ran the ERC to check if anything was wrong. I foudn a few errors of the GNd, and 5V, but with chatgpt's help I was able to fix them. 

Here is a image of the schestamatic that follows the guide:

![This is second image](Project1/images/5t.png)

Now I added my own two componets: Led, and resitor.I rewired everything to get this: 

![This is third image](Project1/images/Okletsgo.png)

After checking again with ERC, I fixed all the warnings, and wiring problems with the help of some people in # Half Life Help 

Finally I got to work on my PCB design, and move on from the shcestamtic. I first went to the edge cut layer, and made my design: 
 
            - A baisc sqaure curved design with two buttons on the side, and holes in all corners. 
                 - Includes the LCD on the top, and LED in the middle. 

After fixing the issues, I routed my wires, and used DRC to check any mistakes (I got 25 wanrings, and 2 errors)

I fixed this through the help of Half life help. I asked many people, and they told me that i had 4 uncconeted wires(silly me)

I fixed those, and got 2 errors and 18 warnigns, just like the guide(so this means nothing is wrong)

Here is my final PCB design(withut routing wires):

![This is fourth image](Project1/images/lol23232.png)

Finally, I did a 3d editor view, and got this; 

![This is fifth image](Project1/images/3DEditor.png)

After that, I went to Arduino IDE go start my coding. Most of my coding details are in my journal in Half Life.( i provided all the information about the code there)
      1. I added liabries
      2. CHanged port to microcontroller XIAO 
      3. Made the code so that when you press a button: a led might light up, the hummity cgets dispaly on LCD, or "Hello might be prinnted on LCD. 
Next I uploaded a desing of new york city as a small feature. After that, I uplaoded my desing into JLCPCB and customized it based on that. 

Thats all! 

ALSO NOTE: For the money/costs, this is a screen shot for PCb design, since i didn't know how to share it for costs. 

Pleaase choose direct global shipping, and this: 

![This is sixth image](Project1/images/shippingproblem.png)

BOM Table :

# Components and Cost

| Part | What it's for | Qty | Total ($) | Vendor |
|---|---|---:|---:|---|
| [Seeed Studio XIAO ESP32-C3](https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html) | Used for the microcontrolelr and controlling everything! | 1 | 4.99 | [See Studio](https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html) |
| [0.96-inch I²C OLED, 128×64](https://www.aliexpress.us/item/3256806179566773.html?src=google\&gatewayAdapt=glo2usa) | To dispaly the text, and hummity around the air. | 1 | 1.09 | [AliExpress](https://www.aliexpress.us/item/3256806179566773.html?src=google\&gatewayAdapt=glo2usa) |
| [MPU-6050 MPU6050](https://www.aliexpress.us/item/2251832613625365.html?utm_source=chatgpt.com\&oppcref=afc922b8-3e9e-4f01-9274-165692347f5a\&gatewayAdapt=4itemAdapt) | For Gyroscope | 1 | 1.09 | [AliExpress](https://www.aliexpress.us/item/2251832613625365.html?utm_source=chatgpt.com\&oppcref=afc922b8-3e9e-4f01-9274-165692347f5a\&gatewayAdapt=4itemAdapt) |
| [DHT11 Sensor](https://www.aliexpress.us/item/3256807193101859.html?spm=a2g0o.productlist.main.6.21c062a4L286ju\&algo_pvid=64ffd2c1-6f33-4a63-8077-6ad4980d00e8\&algo_exp_id=64ffd2c1-6f33-4a63-8077-6ad4980d00e8-5\&pdp_ext_f=%7B%22order%22%3A%2217%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D\&pdp_npi=6%40dis%21USD%211.84%211.09%21%21%211.84%211.09%21%402101d33417917508270772336e11df%2112000040495726382%21sea%21US%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Aeb5bcb9b%3Bm03_new_user%3A-29895%3BpisId%3A5000000218165385\&curPageLogUid=rmCwzObMgEk0\&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007379416611%7C_p_origin_prod%3A) | Used to display temperature. | 1 | 1.09 | [AliExpress](https://www.aliexpress.us/item/3256807193101859.html?spm=a2g0o.productlist.main.6.21c062a4L286ju\&algo_pvid=64ffd2c1-6f33-4a63-8077-6ad4980d00e8\&algo_exp_id=64ffd2c1-6f33-4a63-8077-6ad4980d00e8-5\&pdp_ext_f=%7B%22order%22%3A%2217%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D\&pdp_npi=6%40dis%21USD%211.84%211.09%21%21%211.84%211.09%21%402101d33417917508270772336e11df%2112000040495726382%21sea%21US%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Aeb5bcb9b%3Bm03_new_user%3A-29895%3BpisId%3A5000000218165385\&curPageLogUid=rmCwzObMgEk0\&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007379416611%7C_p_origin_prod%3A) |
| [PCB Part](https://cart.jlcpcb.com/quote?spm=jlcpcb.Public.2006\&spm=Jlcpcb.Instantquote&_t=1791753237824\&up_spm=Jlcpcb.Loginpage.1003) | The main board, also idk how to upload this, so I put my files on github, and took a screenshot for the person buying it! The shipping should be through Gloabl direct which is $7. | 1 | 4.00 | [JLCPCB](https://cart.jlcpcb.com/quote?spm=jlcpcb.Public.2006\&spm=Jlcpcb.Instantquote&_t=1791753237824\&up_spm=Jlcpcb.Loginpage.1003) |
| [Cherry MX-compatible switch](https://www.aliexpress.us/item/3256808470402926.html?spm=a2g0o.cart.0.0.404238dagG5YPF\&mp=1\&pdp_npi=6%40dis%21USD%21USD+7.52%21USD+1.09%21%21USD+1.09%21%21%21%402101d9ef17917538577586282e0d92%2112000046120217083%21ct%21US%21-1%21%211%210%21&_gl=1*18szfre*_gcl_aw*R0NMLjE3OTE3NTM2OTIuQ2p3S0NBanc1NnpXQmhCMEVpd0FkUE9RT2Q3VTU2aDJkVGdMdzExZjh0dEo2TlhGbGVsWHM1UUhCWnpERlNId18tV3A0YVp4RXVyRDZCb0NSMWtRQXZEX0J3RQ..*_gcl_dc*R0NMLjE3OTE3NTM2OTIuQ2p3S0NBanc1NnpXQmhCMEVpd0FkUE9RT2Q3VTU2aDJkVGdMdzExZjh0dEo2TlhGbGVsWHM1UUhCWnpERlNId18tV3A0YVp4RXVyRDZCb0NSMWtRQXZEX0J3RQ..*_gcl_au*MjI5NTY3MjU1LjE3OTE3NTM2OTI.*_ga*ODc4NTE0MzMzMTcwMTgxLjE3OTE3NTAzNDk2Mzk.*_ga_VED1YSGNC7*czE3OTE3NTM2OTEkbzEkZzEkdDE3OTE3NTM4MzIkajIzJGwwJGgw\&gatewayAdapt=glo2usa) | Used for pressing buttons | 1 | 1.09 | [Aliexpress](https://www.aliexpress.us/item/3256808470402926.html?spm=a2g0o.cart.0.0.404238dagG5YPF\&mp=1\&pdp_npi=6%40dis%21USD%21USD+7.52%21USD+1.09%21%21USD+1.09%21%21%21%402101d9ef17917538577586282e0d92%2112000046120217083%21ct%21US%21-1%21%211%210%21&_gl=1*18szfre*_gcl_aw*R0NMLjE3OTE3NTM2OTIuQ2p3S0NBanc1NnpXQmhCMEVpd0FkUE9RT2Q3VTU2aDJkVGdMdzExZjh0dEo2TlhGbGVsWHM1UUhCWnpERlNId18tV3A0YVp4RXVyRDZCb0NSMWtRQXZEX0J3RQ..*_gcl_dc*R0NMLjE3OTE3NTM2OTIuQ2p3S0NBanc1NnpXQmhCMEVpd0FkUE9RT2Q3VTU2aDJkVGdMdzExZjh0dEo2TlhGbGVsWHM1UUhCWnpERlNId18tV3A0YVp4RXVyRDZCb0NSMWtRQXZEX0J3RQ..*_gcl_au*MjI5NTY3MjU1LjE3OTE3NTM2OTI.*_ga*ODc4NTE0MzMzMTcwMTgxLjE3OTE3NTAzNDk2Mzk.*_ga_VED1YSGNC7*czE3OTE3NTM2OTEkbzEkZzEkdDE3OTE3NTM4MzIkajIzJGwwJGgw\&gatewayAdapt=glo2usa) |
| [Keycaps](https://www.aliexpress.us/item/3256811960232273.html?spm=a2g0o.productlist.main.2.23be12036QkBbX\&algo_pvid=a460f664-6d0f-4f7c-ada0-091779c90ee6\&algo_exp_id=a460f664-6d0f-4f7c-ada0-091779c90ee6-1\&pdp_ext_f=%7B%22order%22%3A%22938%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D\&pdp_npi=6%40dis%21GBP%212.76%211.76%21%21%213.53%212.25%21%402103956a17911049055707941e1490%2112000057621889504%21sea%21UK%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Af20e294%3Bm03_new_user%3A-29895%3BpisId%3A5000000218658082\&curPageLogUid=KP8wqdHZI0jA\&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005012146547025%7C_p_origin_prod%3A\&gatewayAdapt=glo2usa4itemAdapt) | For the buttons to press on (only need the 10 pack since cheapest) | 1 | 1.09 | [Aliexpress](https://www.aliexpress.us/item/3256811960232273.html?spm=a2g0o.productlist.main.2.23be12036QkBbX\&algo_pvid=a460f664-6d0f-4f7c-ada0-091779c90ee6\&algo_exp_id=a460f664-6d0f-4f7c-ada0-091779c90ee6-1\&pdp_ext_f=%7B%22order%22%3A%22938%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D\&pdp_npi=6%40dis%21GBP%212.76%211.76%21%21%213.53%212.25%21%402103956a17911049055707941e1490%2112000057621889504%21sea%21UK%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Af20e294%3Bm03_new_user%3A-29895%3BpisId%3A5000000218658082\&curPageLogUid=KP8wqdHZI0jA\&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005012146547025%7C_p_origin_prod%3A\&gatewayAdapt=glo2usa4itemAdapt) |
| 10k resitor&#x20; | For transferring power/controlling power | 1 | 1.09 | [Aliexpress](https://www.aliexpress.us/item/3256801782956510.html?spm=a2g0o.detail.0.0.16a0EHemEHemva\&mp=1\&pdp_npi=6%40dis%21USD%21USD+3.52%21USD+1.09%21%21USD+1.09%21%21%21%402101d3fe17929801363494562e0d28%2112000018268283437%21ct%21US%216215269144%21%211%210%21&_gl=1*11n3lcm*_gcl_aw*R0NMLjE3OTE3NzEwODQuQ2p3S0NBanc1NnpXQmhCMEVpd0FkUE9RT1lLUVFMNmRTSGlRUFl1bFVEeFVHVldmX2Mxa1FZZ1AtYmFNTGZvMElpajkzM0hMSWFOamhCb0NGa1VRQXZEX0J3RQ..*_gcl_dc*R0NMLjE3OTE3NTM2OTIuQ2p3S0NBanc1NnpXQmhCMEVpd0FkUE9RT2Q3VTU2aDJkVGdMdzExZjh0dEo2TlhGbGVsWHM1UUhCWnpERlNId18tV3A0YVp4RXVyRDZCb0NSMWtRQXZEX0J3RQ..*_gcl_au*MjI5NTY3MjU1LjE3OTE3NTM2OTI.*_ga*MTQyNzU0MDA1Ny4xNzkyOTgwMDgy*_ga_VED1YSGNC7*czE3OTI5ODAwODEkbzEkZzEkdDE3OTI5ODAxMzYkajUkbDAkaDA.\&gatewayAdapt=glo2usa) |
| LEDS | For lighting up when button pressed | 1 | 5.04 | [Aliexpress](https://www.aliexpress.us/item/3256803133826213.html?spm=a2g0o.productlist.main.4.7dd5648e9gJHMH\&aem_p4p_detail=202610261629328916696654775920000275276\&algo_pvid=e6b4c795-8cfc-4e7d-b19c-4495f5f9c3b2\&algo_exp_id=e6b4c795-8cfc-4e7d-b19c-4495f5f9c3b2-3\&pdp_ext_f=%7B%22order%22%3A%22818%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D\&pdp_npi=6%40dis%21USD%214.06%211.09%21%21%214.06%211.09%21%402101ef5e17930573728131574e0fcd%2112000025195201401%21sea%21US%216215269144%21ACX%211%210%21n_tag%3A-29919%3Bd%3Aeb5bcb9b%3Bm03_new_user%3A-29894%3BpisId%3A5000000218161405\&curPageLogUid=8aScn0lHstH8\&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005003320140965%7C_p_origin_prod%3A\&search_p4p_id=202610261629328916696654775920000275276_1) |
| Tax & shipping |  |  | 8 |  |
| Total |  |  | 28.57 |  |

**Estimated total: $28.57**



