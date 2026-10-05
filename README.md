<div align="center">

# 🛡️ HYDROGUARD AI
### Next-Gen Spatial Hydrogen Safety & Predictive Fail-Safe System

[![GitHub Pages](https://img.shields.io/badge/Live%20Demo-Dashboard-00f2fe?style=for-the-badge&logo=github)](https://Yonadun.github.io/HydroGuard-AI-Safety-System/Dashboard.html)
[![Wokwi Simulation](https://img.shields.io/badge/Wokwi-Simulation-10b981?style=for-the-badge&logo=circuitverse)](https://wokwi.com/YOUR-WOKWI-LINK)
[![Blynk IoT](https://img.shields.io/badge/Blynk-IoT%20Cloud-3b82f6?style=for-the-badge&logo=blynk)](https://blynk.cloud)

<p align="center">
  <b>An AI-driven Edge Computing Safety Ecosystem for Real-Time Hydrogen Leak Localization, Dynamic Density Analytics & Automated Hardware Isolation.</b>
</p>

---

</div>

## 🌟 Executive Overview

**HydroGuard AI** is built to solve critical industrial safety challenges in hydrogen handling. By combining **Edge Computing (ESP32)** for instant fail-safe isolation with a **High-Tech Spatial AI Dashboard**, the system instantly locates gas leaks, measures density percentages, and provides hands-free spatial audio alerts.

---

## 🚀 Key Technological Features

| Feature | Description | Tech Stack |
| :--- | :--- | :--- |
| **⚡ Edge Hardware Fail-Safe** | Triggers isolation valves (<1s) independently during network loss. | ESP32, Relay, MQ-2 Sensor |
| **📍 Spatial Leak Localization** | Pinpoints exact leak zones (*e.g., Zone B - Main Valve*) & density %. | Multi-Sensor Fusion Engine |
| **🗣️️ Spatial AI Voice Alerts** | Continuous, hands-free spatial audio warnings via Web Speech API. | Web Speech Synthesis Engine |
| **📊 Dynamic Real-Time Telemetry** | Smooth 60FPS Chart.js telemetry visualization with critical threshold modes. | Chart.js, HTML5 Canvas |
| **📱 Cloud Mobile Alerts** | Instant push notifications sent to mobile devices during hazards. | Blynk Cloud Webhooks |

---

## 🎮 Interactive Demo & Simulation Controls

Evaluators can directly test all system functionalities using the links below:

### 1. 🌐 Live Spatial AI Safety Dashboard
> Access the fully reactive, web-based monitoring interface with dynamic spatial alerts.
> 
> 👉 **[Launch Live Dashboard](https://Yonadun.github.io/HydroGuard-AI-Safety-System/Dashboard.html)**

### 2. ⚡ Wokwi Hardware Circuit Simulation
> Test the physical ESP32 sensor response, relay isolation valve actuation, and buzzer alarms live in the cloud.
> 
> 👉 **[Run Wokwi Circuit Simulation](https://wokwi.com/projects/476764266571361281)**

---

## 🛠️ System Architecture & Workflow

```text
[ MQ-2 Gas Sensor ] ---> [ ESP32 Edge Core ] ---> (PPM >= 2000?)
                                  |
            +---------------------+---------------------+
            | (HARDWARE FAIL-SAFE)| (CLOUD TELEMETRY)   |
            v                     v                     v
   [ Relay Valve CLOSED ]   [ Blynk Mobile ]    [ AI Safety Terminal ]
   [ Audio Alarm ACTIVE ]   [ Push Alert   ]    [ Spatial Localization ]
   [ Hazard Red Indicator]                     [ AI Voice Output    ]
