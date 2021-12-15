/**
 **************************************************
 *
 * @file        set_digipot.ino
 * @brief       This example shows how to set desired value for digipot. It first sets digipot to 0 percent (wiper
 *connected to GND), then 25% from GND, after that 50%, 75% and at the and it connects wiper to A pad.
 *
 * Product: Digipot 5k      - solde.red/333046
 *          Digipit 10k     - solde.red/333091
 *          Digipot 50k     - solde.red/333092
 *          Digipot 100k    - solde.red/333093
 *
 * @authors     Borna Biro @ soldered.com
 ***************************************************/

#include "MCP4018-SOLDERED.h" // Include Soldered library for MCP4018 Digipot.

MCP4018_SOLDERED digipot; // Create object for Digipot library.

void setup()
{
    Serial.begin(115200); // Initialize serial communication at 115200 bauds.
    digipot.begin();      // Initialize Digipot library.
}

void loop()
{
    int wiper;

    // Set digipot wiper to 0% (connected to GND).
    wiper = 0;
    digipot.setWiper(wiper);
    printDigipotData(wiper);
    delay(2000);

    // Set digipot wiper to 25%.
    wiper = 25;
    digipot.setWiper(wiper);
    printDigipotData(wiper);
    delay(2000);

    // Set digipot wiper to 50%.
    wiper = 50;
    digipot.setWiper(wiper);
    printDigipotData(wiper);
    delay(2000);

    // Set digipot wiper to 75%.
    wiper = 75;
    digipot.setWiper(wiper);
    printDigipotData(wiper);
    delay(2000);

    // Set digipot wiper to 100% (Wiper connected to A pad).
    wiper = 100;
    digipot.setWiper(wiper);
    printDigipotData(wiper);
    delay(2000);
}

// Function prints wiper position on Serial Monitor.
void printDigipotData(int _v)
{
    Serial.print("Digipot wiper: ");
    Serial.print(_v, DEC);
    Serial.println('%');
}