# Kitchen-Companion-
Because doing chores manually is a bug, not a feature. An Arduino- powered IoT task terminal and wellness tracker that forces your family to actually help around the house. Less mom burnout, more code. Hope it helps!
## 💡 Why I Built This

Being a homemaker is exhausting. Watching my mom carry the daily workload around the house made me realize how easy it is for primary caregivers to burn out. I wanted to build something physical and interactive to help offload some of that planning, get the rest of the family to jump in, and make sure she actually takes breaks to rest and hydrate.

I’m open-sourcing this so anyone facing the same issue can build one for their own home and support the caregivers in their lives!

---

## ✨ Features

* **Easy Task Claiming:** Family members can tap an RFID card or hit a button to take ownership of a chore so mom doesn't have to ask twice.
* **Smart Rest & Hydration Alerts:** Soft chimes and LED lights remind caregivers to sit down, take a breather, and grab some water.
* **Simple Display:** A clear screen showing current tasks, who's on what, and status updates.
* **Cloud Connectivity (Optional):** Can sync up with a web dashboard to keep track of completed chores over time.

---

## 🛠️ Parts List

* **Brain:** Arduino (Uno, Nano, or Mega)
* **Screen:** 16x2 LCD Display (I2C module makes wiring easier!)
* **Controls:** Push buttons or an RC522 RFID reader + tags
* **Sensors & Alerts:** Buzzer, LEDs, resistors, and a motion or light sensor
* **Extras:** Breadboard and jumper wires

---

## 🚀 How to Set It Up

1. Download or clone this repository.
2. Open `Kitchenassistant.ino` in the Arduino IDE.
3. Wire up your components using the pin map in the code comments.
4. Upload the code to your Arduino, and you're good to go!
