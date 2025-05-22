const int trigPin = 9; //triggerتعريف الدبوس رقم 9 علي انه 
const int echoPin = 10;  // echo تعريف دبوس رقم 10 علي انه
long duration;  //متغير لحفظ زمن ارتداد الموجه
float distance;  // متغير لحفظ المسافه المحسوبة

void setup() {
  Serial.begin(9600);      //بدء الاتصال بسرعه 9600   
  pinMode(trigPin, OUTPUT);   //   كأنه مخرج trigger تعين دبوس 
  pinMode(echoPin, INPUT);    // كأنه مدخل Echo تعين دبوس 
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);    //  trigger ارسال اشارة منخفضة ل   
  delayMicroseconds(2);   //الزمن بين الاشارات المرسله

  // Trigger the sensor     //ارسال  اشارة عالية لتنشيط الحساس
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);  //قراءة زمن ارتداد الموجه بواسطة الدبوس

  // Calculate distance in cm
  distance = duration * 0.034 / 2;     //حساب المسافه بالسنتيمتر

  // Print the distance
  Serial.print("Distance: ");    // عرض المسافه علي الشاشه
  Serial.print(distance);
  Serial.println("cm");

  delay(500);    // الزمن بين كل مرة يتم فيها قياس المسافه
                     //    انتظر نصف ثانية قبل القياس التالي
}
