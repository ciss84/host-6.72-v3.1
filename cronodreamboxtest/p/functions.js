

function load_JB()
{	var jbDone=getCookie("JB");
	var spoofed=navigator.userAgent.indexOf("6.72")>=0 ? false : true;
	if (!spoofed && (jbDone == "" || jbDone == "START")){
		setCookie("JB","START",1);
		exploit();	
	}else{
		
	}
}

function exploit(){
	document.getElementById("msgs").innerHTML="EXECUTANDO AUTO JAILBREAK AGUARDE!!";
	setTimeout(function(){jb();}, 500);
}


function getCookie(name) {
  var name = name + "=";
  var decodedCookie = decodeURIComponent(document.cookie);
  var ca = decodedCookie.split(';');
  for(var i = 0; i < ca.length; i++) {
    var c = ca[i];
    while (c.charAt(0) == ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  return "";
}

function setCookie(name, value, mins) {
  var d = new Date();
  d.setTime(d.getTime() + (mins*60*1000));
  var expires = "expires="+ d.toUTCString();
  document.cookie = name + "=" + value + ";" + expires + ";path=/";
}

function deleteCookie(name) {
  document.cookie = name + "=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
}
