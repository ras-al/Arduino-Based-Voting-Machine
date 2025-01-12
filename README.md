# Arduino-Based Electronic Voting Machine

## Project Description
This project demonstrates a simple and effective electronic voting machine using an Arduino microcontroller. It includes components such as push buttons for voting, approval, and result display, an LCD screen to show voting progress and results, and a buzzer for audio feedback.

The voting machine allows users to cast votes for candidates, approve their selection, and view the final results upon completion.

## Components Used
- **Arduino Uno**: The microcontroller that controls the voting machine's logic.
- **Push Buttons**: Used for selecting candidates, approval, and displaying results.
- **Buzzer**: Provides audio feedback when a vote is cast or when the results are displayed.
- **LCD Display (16x2)**: Shows the current voting status, vote counts, and results.
- **Jumper Wires**: Connects various components to the Arduino board.
- **Resistors**: Used for button pull-ups and current limiting.

## Features
- **Voting Buttons**: Allows users to cast votes for different candidates.
- **Approval Button**: Confirms the selected vote and locks in the choice.
- **Result Button**: Displays the total votes for each candidate and shows the final result.
- **Buzzer Feedback**: Sounds an audible confirmation when a vote is successfully cast.
- **LCD Display**: Provides real-time feedback and displays vote counts and results.

## Installation
1. **Hardware Setup**:
   - Connect the components as per the wiring diagram provided.
   - Ensure the correct pin configuration for the LCD, buttons, and buzzer.
   
2. **Software Setup**:
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Install the necessary libraries:
     - `LiquidCrystal` (for LCD display).
   
3. **Uploading the Code**:
   - Open the Arduino IDE and load the `VotingMachine.ino` sketch.
   - Select the correct board and port from the Tools menu.
   - Click **Upload** to transfer the code to the Arduino Uno.

4. **Testing**:
   - After uploading the code, power up the system (either via USB or a battery).
   - Test each button to ensure the voting, approval, and result display functions are working correctly.

## Code Explanation
- **Voting Logic**: The code reads the state of the voting buttons. Each button corresponds to a candidate. When a button is pressed, the vote is registered.
- **Approval**: After selecting a candidate, the user presses the approval button to confirm the vote. A confirmation sound (buzzer) is triggered.
- **Result Display**: When the result button is pressed, the LCD displays the vote counts for each candidate.

## Project Files
- **VotingMachine.ino**: Arduino code for the voting machine.
- **wiring-diagram.png**: A wiring diagram showing how the components are connected.

## Conclusion
This project offers a hands-on way to learn about Arduino programming, circuit design, and building a functional system. It provides an effective solution for an electronic voting system that can be easily replicated and expanded.

Feel free to modify, enhance, or extend this project to fit your needs. Happy coding!

## License
This project is open-source and free to use. You can modify or distribute the code as needed.

