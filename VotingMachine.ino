#include <LiquidCrystal.h>

// Initialize the LCD (pins 12, 11, 5, 4, 3, 2)
LiquidCrystal lcd(12, 11, A0,A1,A2,A3);

// Pins
const int redLED = 8;
const int greenLED = 9;
const int buzzer = 10;

const int approveButton = 2;
const int resultButton = 3;
const int candidate1Button = 4;
const int candidate2Button = 5;
const int candidate3Button = 6;
const int notaButton = 7;

// Variables
int votes[4] = {0, 0, 0, 0}; // [Candidate 1, Candidate 2, Candidate 3, NOTA]
bool votingAllowed = false;

void setup() {
  // Initialize pins
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(approveButton, INPUT_PULLUP);
  pinMode(resultButton, INPUT_PULLUP);
  pinMode(candidate1Button, INPUT_PULLUP);
  pinMode(candidate2Button, INPUT_PULLUP);
  pinMode(candidate3Button, INPUT_PULLUP);
  pinMode(notaButton, INPUT_PULLUP);

  // Start LCD (standard 16x2 LCD)
  lcd.begin(16, 2);  // Set the number of columns and rows
  lcd.print("Voting Machine");
  delay(2000);  // Display initial message for 2 seconds
  lcd.clear();
  digitalWrite(redLED, HIGH); // Red LED ON initially
}

void loop() {
  // Officer approval process
  if (digitalRead(approveButton) == LOW) {
    votingAllowed = true;
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    lcd.clear();
    lcd.print("You can vote");
  }

  // Voting process
  if (votingAllowed) {
    if (digitalRead(candidate1Button) == LOW) {
      castVote(0, "C-1");
    } else if (digitalRead(candidate2Button) == LOW) {
      castVote(1, "C-2");
    } else if (digitalRead(candidate3Button) == LOW) {
      castVote(2, "C-3");
    } else if (digitalRead(notaButton) == LOW) {
      castVote(3, "NOTA");
    }
  }

  // Result display with beep-beep-beep
  if (digitalRead(resultButton) == LOW) {
    // Beep three times for result
    beepResult();
    displayResults();
    resetVoting();
  }
}

void castVote(int candidate, String name) {
  votingAllowed = false;
  votes[candidate]++;
  
  // Buzzer sound when a candidate or NOTA is selected
  tone(buzzer, 1000, 2000); // Buzzer sound for 0.5 seconds
  
  lcd.clear();
  lcd.print("Voted: " + name);
  delay(3000); // Show selection for 3 seconds
  lcd.clear();
  lcd.print("Wait for next");
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
}

void beepResult() {
  // Repeated beeping for 3 short beeps when the result button is pressed
  for (int i = 0; i < 3; i++) {
    tone(buzzer, 1000, 100);  // 1000 Hz for 300 ms
    delay(300);  // Wait between beeps
  }
}

void displayResults() {
  lcd.clear();
  lcd.print("Votes:");

  // Display the votes for each candidate and NOTA
  lcd.setCursor(0, 1);  // Move cursor to the second line
  lcd.print("C1: ");
  lcd.print(votes[0]);
  lcd.print(" C2: ");
  lcd.print(votes[1]);
  delay(2000); // Wait for 2 seconds to show votes for candidates 1 and 2

  lcd.clear();
  lcd.print("Votes:");
  lcd.setCursor(0, 1);
  lcd.print("C3: ");
  lcd.print(votes[2]);
  lcd.print(" NOTA: ");
  lcd.print(votes[3]);
  delay(2000); // Wait for 2 seconds to show votes for candidate 3 and NOTA

  // Find the maximum vote count
  int maxVotes = 0;
  for (int i = 0; i < 4; i++) {
    if (votes[i] > maxVotes) {
      maxVotes = votes[i];
    }
  }

  // Count how many candidates or NOTA have the maximum votes
  int maxCount = 0;
  for (int i = 0; i < 4; i++) {
    if (votes[i] == maxVotes) {
      maxCount++;
    }
  }

  // Display the result
  lcd.clear();
  if (maxCount > 1) {
    // There is a draw
    lcd.print("Draw: ");
    lcd.setCursor(0, 1);
    if (votes[0] == maxVotes) lcd.print("C1 ");
    if (votes[1] == maxVotes) lcd.print("C2 ");
    if (votes[2] == maxVotes) lcd.print("C3 ");
    if (votes[3] == maxVotes) lcd.print("NOTA ");
  } else {
    // No draw, check if NOTA wins
    lcd.print("Winner is: ");
    if (votes[0] == maxVotes) {
      lcd.print("C1");
    } else if (votes[1] == maxVotes) {
      lcd.print("C2");
    } else if (votes[2] == maxVotes) {
      lcd.print("C3");
    } else if (votes[3] == maxVotes) {
      lcd.print("Nobody wins"); // If NOTA wins
    }
  }

  delay(3000); // Display the result for 3 seconds
}

void resetVoting() {
  // Long sound after reset
  tone(buzzer, 1000, 1500); // Long buzzer sound (1.5 seconds)
  delay(1500); // Wait for the long sound to finish
  
  // Reset votes for next round
  delay(2000); // Wait before resetting
  for (int i = 0; i < 4; i++) {
    votes[i] = 0; // Reset votes
  }

  // Clear the LCD and reset LEDs
  lcd.clear();
  lcd.print("Voting Reset");
  digitalWrite(redLED, HIGH); // Red LED ON
  digitalWrite(greenLED, LOW); // Green LED OFF
  votingAllowed = false;
  delay(2000); // Wait for 2 seconds before next voting round
  lcd.clear();
  lcd.print("Start New Vote");
}
