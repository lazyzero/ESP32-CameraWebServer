# ESP32-CameraWebServer

This is a code refactored version of the **"ESP32 CameraWebServer using the Arduino framework"** for the PlatformIO build environment.

Find the original code here [https://github.com/espressif/arduino-esp32/tree/master/libraries/ESP32/examples/Camera/CameraWebServer](https://github.com/espressif/arduino-esp32/tree/master/libraries/ESP32/examples/Camera/CameraWebServer)

## Compile requirements

- rename or copy lib/App/App.hpp.sample to lib/App/App.hpp
  and change &lt;your wifi ssid> and &lt;your wifi password>

## Changing the index.html.gz arrays from camera_index.h

Browse to the very cool tool from [CyberChef's](https://gchq.github.io/CyberChef/) and use the both following receipts to convert the index.html in a fromat you can edit or past into camera_index.h.

### Compress for camera_index.h

```
Gzip('Dynamic Huffman Coding','index.html','',false)
To_Hex('Comma')
Find_/_Replace({'option':'Regex','string':','},', 0x',true,false,true,false)
Find_/_Replace({'option':'Regex','string':'^'},'0x',true,false,true,false)
```

### Extract HTML

```
Remove_whitespace(true,true,true,true,true,false)
Find_/_Replace({'option':'Simple string','string':','},'',true,false,true,false)
From_Hex('0x')
Gunzip()
```


### Determine length of array

```
Count_occurrences({'option':'Regex','string':'0x'})
```
