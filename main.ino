 class Pulsador {
  private:
    int pin;
    bool flanco = HIGH;
    bool estado_anterior = !flanco;

    //metodo
  public:
    Pulsador(int p) {
      pin = p;

      pinMode(pin, INPUT);
    }

    void setFlanco(bool f) {
      flanco = f;
      estado_anterior = !flanco;
    }

    //metodos o acciones
    bool getIsPress() {
      bool estado_actual = digitalRead(pin);
      bool estado = (estado_anterior != estado_actual) && estado_actual == flanco;
      estado_anterior = estado_actual;
      return estado;
    }

    String getIsPressText() {
      if (getIsPress()) return "PRESS";
      else return "IS NOT PRESS";
    }

};




//motor

#define MOTOR_IS 0
#define MOTOR_EN 0
#define MOTOR_PWM 0



class Motor {
private:
  int pin_is, pin_en, pin_pwm;
  int velocidad = 100;


public:
  Motor(int pr1, int pr2, int pr3) {
    pin_is = pr1;
    pin_en = pr2;
    pin_pwm = pr3;


    pinMode(pin_is, OUTPUT);
    pinMode(pin_en, OUTPUT);
    pinMode(pin_pwm, OUTPUT);

    digitalWrite(pin_is, LOW);
    digitalWrite(pin_en, HIGH);
  }


  void avanzar() {
    digitalWrite(pin_en, LOW);
    analogWrite(pin_pwm, velocidad);
  }

  void retroceder() {
    analogWrite(pin_pwm, LOW);
    digitalWrite(pin_en, velocidad);
  }

  void frenar() {
    digitalWrite(pin_en, LOW);
    digitalWrite(pin_pwm, LOW);
  }

  void subir_velocidad() {
    velocidad = velocidad + 10;
    if (velocidad > 255) velocidad = 255;
  }
  void bajar_velocidad() {
    velocidad = velocidad - 10;
    if(velocidad<0)velocidad=0;
  }
};
#define PIN_PULSADOR_1 3
Pulsador *p1 = new Pulsador(PIN_PULSADOR_1);
Motor *motor = new Motor(MOTOR_IS, MOTOR_EN, MOTOR_PWM);



void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}