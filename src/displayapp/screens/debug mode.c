
#include <stdio.h>
#include <stdbool.h>
#include "accelerometer.h"
#include "heart_rate.h"
#include "ambient_light.h"

void consoleLog(const char* message) {
    printf("[Console Log] %s\n", message);
}

bool runAccelerometerTest() {
    consoleLog("Running accelerometer test...");

    // Initialize the accelerometer
    accelerometer_init();
    consoleLog("Accelerometer initialized.");

    // Read accelerometer data
    int16_t x, y, z;
    accelerometer_read(&x, &y, &z);
    consoleLog("Accelerometer data read.");

    // Print the accelerometer data
    printf("Accelerometer Data:\n");
    printf("X: %d\n", x);
    printf("Y: %d\n", y);
    printf("Z: %d\n", z);

    // Perform some checks on the accelerometer data
    bool accelerometerTestPassed = true;
    if (x == 0 && y == 0 && z == 0) {
        consoleLog("Accelerometer test failed: all values are zero.");
        accelerometerTestPassed = false;
    } else {
        consoleLog("Accelerometer test passed.");
    }

    return accelerometerTestPassed;
}

bool runHeartRateTest() {
    consoleLog("Running heart rate test...");

    // Initialize the heart rate monitor
    heart_rate_init();
    consoleLog("Heart rate monitor initialized.");

    // Read heart rate data
    uint8_t heartRate;
    heart_rate_read(&heartRate);
    consoleLog("Heart rate data read.");

    // Print the heart rate data
    printf("Heart Rate: %d bpm\n", heartRate);

    // Perform some checks on the heart rate data
    bool heartRateTestPassed = true;
    if (heartRate == 0) {
        consoleLog("Heart rate test failed: heart rate is zero.");
        heartRateTestPassed = false;
    } else {
        consoleLog("Heart rate test passed.");
    }

    return heartRateTestPassed;
}

bool runAmbientLightTest() {
    consoleLog("Running ambient light test...");

    // Initialize the ambient light sensor
    ambient_light_init();
    consoleLog("Ambient light sensor initialized.");

    // Read ambient light data
    uint16_t lightLevel;
    ambient_light_read(&lightLevel);
    consoleLog("Ambient light data read.");

    // Print the ambient light data
    printf("Light Level: %u lux\n", lightLevel);

    // Perform some checks on the ambient light data
    bool ambientLightTestPassed = true;
    if (lightLevel == 0) {
        consoleLog("Ambient light test failed: light level is zero.");
        ambientLightTestPassed = false;
    } else {
        consoleLog("Ambient light test passed.");
    }

    return ambientLightTestPassed;
}

int main() {
    consoleLog("Hello, PineTime!");

    int choice;
    bool allTestsPassed = true;

    consoleLog("Select the test you want to run:");
    consoleLog("1. Accelerometer Test");
    consoleLog("2. Heart Rate Test");
    consoleLog("3. Ambient Light Test");
    consoleLog("0. Exit");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 0:
            consoleLog("Exiting...");
            return 0;
        case 1:
            if (!runAccelerometerTest()) {
                allTestsPassed = false;
            }
            break;
        case 2:
            if (!runHeartRateTest()) {
                allTestsPassed = false;
            }
            break;
        case 3:
            if (!runAmbientLightTest()) {
                allTestsPassed = false;
            }
            break;
        default:
            consoleLog("Invalid choice. Exiting...");
            return 0;
    }

    if (allTestsPassed) {
        consoleLog("All tests passed!");
    } else {
        consoleLog("Some tests failed.");
    }

    return 0;
}
