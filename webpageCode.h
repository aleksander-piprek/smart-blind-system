//=========================================//
//HTML + CSS + JavaScript codes for webpage//
//=========================================//
const char webpageCode[] =
R"=====(
<!DOCTYPE html>
<html>
<!------------------------------HEAD--------------------------------->
<head>
    <style>
        #btn
        {
          display: inline;
          text-decoration: none;
          background: red;
          color:rgba(0, 0, 255, 0.7);
          font: 80px calibri;
          box-shadow: 0px 0px 10px 15px #000000;
          border: solid 10px rgba(255, 255, 0, 0.9);
          cursor: pointer;
        }
        body {font-family: "Calibri"; background-color: grey}
        h1   {color: whitesmoke; text-align:center; font-size: 50px;}
    </style>
    
    <script type="text/javascript"> 
      function display_c(){
        var refresh=1000; // Refresh rate in milli seconds
        mytime=setTimeout('display_ct()',refresh)
      }
      
      function display_ct() {
        var x = new Date()
        document.getElementById('ct').innerHTML = x;
        display_c();
       }
    </script>
</head>

<!----------------------------BODY------------------------------------>
<body onload=display_ct();>
    <h1>
        Smart Blinds <br><br>
        <a href="/clk" id="btn"> Clockwise </a> <br><br>
        <a href="/cclk" id="btn"> Counter-clockwise </a> <br><br>
        <span id='ct' ></span><br><br><br>
    </h1>
</body>
</html>
)=====";
