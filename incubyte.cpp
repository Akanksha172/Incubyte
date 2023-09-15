#include <bits/stdc++.h>
using namespace std;

class Spacecraft {
public:
    // Constructor to initialize spacecraft's position and direction
    Spacecraft(int startX, int startY, int startZ, char startDirection) {
        x = startX;
        y = startY;
        z = startZ;
        direction = startDirection;
    }

    // Method to move the spacecraft forward or backward
    void move(char command) {
        switch (command) {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
            default:
                break; // Handle invalid commands if needed
        }
    }

    // Method to turn the spacecraft left or right
    void turn(char command) {
        switch (command) {
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
            default:
                break; // Handle invalid commands if needed
        }
    }

    // Method to turn the spacecraft up or down
    void tilt(char command) {
        switch (command) {
            case 'u':
                tiltUp();
                break;
            case 'd':
                tiltDown();
                break;
            default:
                break; // Handle invalid commands if needed
        }
    }

    // Method to display the current position and direction of the spacecraft
    void displayPosition() {
        std::cout << "Final Position: (" << x << ", " << y << ", " << z << ")" << std::endl;
        std::cout << "Final Direction: " << direction << std::endl;
    }

private:
    int x, y, z;
    char direction; // N, S, E, W, Up, Down

    void moveForward() {
        // Update position based on current direction
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'U':
                z++;
                break;
            case 'D':
                z--;
                break;
        }
    }

    void moveBackward() {
        // Update position based on current direction
        switch (direction) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x--;
                break;
            case 'W':
                x++;
                break;
            case 'U':
                z--;
                break;
            case 'D':
                z++;
                break;
        }
    }

    void turnLeft() {
        // Update direction by rotating 90 degrees to the left
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
            case 'U':
                direction = 'N'; 
                break;
            case 'D':
                direction = 'S'; 
                break;
        }
    }

    void turnRight() {
        // Update direction by rotating 90 degrees to the right
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
            case 'U':
                direction = 'S'; 
                break;
            case 'D':
                direction = 'N'; 
                break;
        }
    }

    void tiltUp() {
        // Update direction by tilting up
        direction = 'U';
    }

    void tiltDown() {
        // Update direction by tilting down
        direction = 'D';
    }
};

int main() {
    // Initialize spacecraft at a specific position and direction
    Spacecraft spacecraft(0, 0, 0, 'N');

    // Sample commands to test the spacecraft's movement and rotation
    char commands[] = {'f', 'r', 'u', 'b', 'l'};

    // Execute the commands
    for (char command : commands) {
        switch (command) {
            case 'f':
            case 'b':
                spacecraft.move(command);
                break;
            case 'l':
            case 'r':
                spacecraft.turn(command);
                break;
            case 'u':
            case 'd':
                spacecraft.tilt(command);
                break;
        }
    }

    // Display the final position and direction
    spacecraft.displayPosition();

    return 0;
}
