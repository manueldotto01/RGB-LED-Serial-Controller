const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

String input = "";

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.println("Send R G B values like: R255 G100 B50");
}

void loop() {
  if (Serial.available()) {
    delay(10); // Wait for the full string to be received
    input = Serial.readString();
    parseColor(input);
  }
}

void parseColor(String data) {
  int rIndex = data.indexOf('R');
  int gIndex = data.indexOf('G');
  int bIndex = data.indexOf('B');

  if (rIndex != -1 && gIndex != -1 && bIndex != -1) {
    // Extract RGB values from the input string
    int red = data.substring(rIndex + 1, gIndex).toInt();
    int green = data.substring(gIndex + 1, bIndex).toInt();
    int blue = data.substring(bIndex + 1).toInt();

    // Write to the RGB pins
    analogWrite(redPin, red);
    analogWrite(greenPin, green); 
    analogWrite(bluePin, blue);   

    Serial.print("Color set to: R=");
    Serial.print(red);
    Serial.print(" G=");
    Serial.print(green);
    Serial.print(" B=");
    Serial.println(blue);
  } else {
    Serial.println("Invalid input. Use format: Rxxx Gxxx Bxxx");
  }
}
