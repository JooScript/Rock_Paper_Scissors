# 🎮 Simple Rock Paper Scissors – C++ Console Game

## 📌 Overview
This is a simple **Rock Paper Scissors** game developed in C++. The game follows **Separation of Concerns (SoC)** principles, ensuring a modular, clean, and maintainable code structure.

## 🚀 Key Features
✔ **Separation of Concerns (SoC)** – Organized into multiple functions for **Game Logic, User Interaction, and AI**.  
✔ **User Input Handling** – Validates user input to ensure a smooth gameplay experience.  
✔ **Console-Based UI** – A simple, lightweight, and efficient C++ application.  
✔ **AI Opponent** – Uses `cstdlib` and `ctime` for random AI moves.  

## 🛠️ Tech Stack
🔹 **Language:** C++  
🔹 **Architecture:** Separation of Concerns (Game Logic, Input Handling, Display)  
🔹 **Randomization:** `cstdlib` and `ctime` for AI decision-making  

## 🎯 How It Works
1. **Player selects**: Rock, Paper, or Scissors.
2. **AI generates**: A random choice.
3. **Game logic determines**: The winner based on standard rules:
   - Rock beats Scissors
   - Scissors beats Paper
   - Paper beats Rock
4. **Game result displayed**: Win, Lose, or Draw.

## 🔧 Installation & Usage
1. **Clone the repository**:
   ```bash
   git clone https://github.com/Yousef-Refat/Rock_Paper_Scissors.git
   ```
2. **Navigate to the project directory**:
   ```bash
   cd Rock_Paper_Scissors
   ```
3. **Compile the code**:
   ```bash
   g++ -o Rock_Paper_Scissors main.cpp -std=c++11
   ```
4. **Run the game**:
   ```bash
   ./Rock_Paper_Scissors
   ```

## 🚀 Future Improvements
- **Best of 3 or 5 Mode** – Allow multiple rounds.
- **Score Tracking** – Maintain player and AI scores.
- **GUI Version** – Convert to a graphical interface using a UI framework.

## 📜 License
This project is open-source under the **MIT License**.

## 🤝 Contributing
Pull requests are welcome! Feel free to suggest improvements.
