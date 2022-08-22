//motores
//MOTOR_IZQUIERDO

#define MOTOR_IZQUIERDO_R_IS 0
#define MOTOR_IZQUIERDO_R_EN 0
#define MOTOR_IZQUIERDO_R_PWM 0
#define MOTOR_IZQUIERDO_L_IS 0
#define MOTOR_IZQUIERDO_L_EN 0
#define MOTOR_IZQUIERDO_L_PWM 0

//MOTOR_DERECHO

#define MOTOR_DERECHO_R_IS 0
#define MOTOR_DERECHO_R_EN 0
#define MOTOR_DERECHO_R_PWM 0
#define MOTOR_DERECHO_L_IS 0
#define MOTOR_DERECHO_L_EN 0
#define MOTOR_DERECHO_L_PWM 0

class Motor {
private:
  int pin_r_is, pin_r_en, pin_r_pwm, pin_l_is, pin_l_en, pin_l_pwm;
  int velocidad = 100;


public:
  Motor(int pr1, int pr2, int pr3, int pl1, int pl2, int pl3) {
    pin_r_is = pr1;
    pin_r_en = pr2;
    pin_r_pwm = pr3;
    pin_l_is = pl1;
    pin_l_en = pl2;
    pin_l_pwm = pl3;

    pinMode(pin_r_is, OUTPUT);
    pinMode(pin_r_en, OUTPUT);
    pinMode(pin_r_pwm, OUTPUT);
    pinMode(pin_l_is, OUTPUT);
    pinMode(pin_l_en, OUTPUT);
    pinMode(pin_l_pwm, OUTPUT);

    digitalWrite(pin_r_is, LOW);
    digitalWrite(pin_l_is, LOW);
    digitalWrite(pin_r_en, HIGH);
    digitalWrite(pin_l_en, HIGH);
  }


  void avanzar() {
    digitalWrite(pin_r_pwm, LOW);
    analogWrite(pin_l_pwm, velocidad);
  }

  void retroceder() {
    analogWrite(pin_l_pwm, LOW);
    digitalWrite(pin_r_pwm, velocidad);
  }

  void frenar() {
    digitalWrite(pin_r_pwm, LOW);
    digitalWrite(pin_l_pwm, LOW);
  }

  void subir_velocidad() {
    velocidad = velocidad + 10;
  }
  void bajar_velocidad() {
    velocidad = velocidad - 10;
  }
};

Motor *motor_izquierdo = new Motor(MOTOR_IZQUIERDO_R_IS, MOTOR_IZQUIERDO_R_EN, MOTOR_IZQUIERDO_R_PWM, MOTOR_IZQUIERDO_L_IS, MOTOR_IZQUIERDO_L_EN, MOTOR_IZQUIERDO_L_PWM);
Motor *motor_derecho = new Motor(MOTOR_DERECHO_R_IS, MOTOR_DERECHO_R_EN, MOTOR_DERECHO_R_PWM, MOTOR_DERECHO_L_IS, MOTOR_DERECHO_L_EN, MOTOR_DERECHO_L_PWM);


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}