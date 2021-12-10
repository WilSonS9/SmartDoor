
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns


// Define the Keymap
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

int rows[4] = {12,13,14,15};


int cols[4] = {5,4,0,2};


int row = 0;
int col =0;

void setup()
{
  for (int i = 0; i < 4; i++){
     pinMode(cols[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++){
     pinMode(rows[i], INPUT_PULLUP);
  }

  Serial.begin(9600); 
}

void loop()
{ // Efter test av alla rows visar sig knapparna # och D (3 och 4 i rad 4)funka som förväntat, resten inte. 
  // Varje gång man trycker på antingen knapp 3 eller knapp 4 i en rad aktiveras raden, men den stängs inte av förrän man trycker på antingen knapp 1 eller 2 i samma rad. undantaget är rad 4.
  // Col 1 visar High som default, eller hoppar mellan de två värdena frantically om man inte trycker någonting. hela column 1 visar low, på det sättet man vil att de ska göra, men knappen 0 visar också detta värde, varför vet jag inte. 
  
  for (int i = 0; i < 4; i++){
     digitalWrite(cols[i], LOW);
     for (int y = 0; y < 4; y++){
      if (digitalRead(rows[y]) == LOW){
        Serial.println(keys[y][i]);
        delay(200);
      }
     }
     digitalWrite(cols[i], HIGH);
     delay(10);
  }
 
  
  }
