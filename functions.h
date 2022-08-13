//=====================//
//Web Handler Functions//
//=====================//
void webPage(){
  webServer.send(200,"text/html", webpageCode);
}

void Clockwise(){
  digitalWrite(dirPin,HIGH); 
    for(int x = 0; x < i; x++){
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(1000); 
  }
  Serial.print("Rotating clockwise...");
  webServer.send(200, "text/html", webpageCode);
}

void CounterClockwise(){
  digitalWrite(dirPin,LOW); 
    for(int x = 0; x < i; x++){
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(1000); 
  }
  Serial.print("Rotating counter clockwise...");
  webServer.send(200, "text/html", webpageCode);
}
