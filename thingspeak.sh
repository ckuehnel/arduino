#!/bin/sh

echo "Send data to Thingspeak Server"

#Thingspeak
api_key='AQWD9CYXME8K5O0R'

DATE="$(date +"%d-%m-%Y")"
read TEMP < /tmp/TEMP		
echo "Temperature   = $TEMP *C"
read HUMI < /tmp/HUMI		
echo "Rel. Humidity = $HUMI %"

curl --insecure --data \
     "api_key=$api_key&field1=$TEMP&field2=$HUMI&field3=$DATE" \
     https://api.thingspeak.com/update  > log 2>&1
