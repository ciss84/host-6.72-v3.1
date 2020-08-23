let level = 0;

if (fwVersion != null) {
  document.getElementById("firmware").innerHTML =
    '<span class="firmware">Firmware:' + " " + fwVersion + "</span>";
}
if (alertfirmware == true) {
  var msg =
    "ATTENTION! Nous avons détecté que votre PlayStation 4 fonctionne sous FW " +
    fwVersion +
    ", qui n'est pas compatible avec PS4HostCS";
  if (document.getElementById("menulist") != null) {
    document.getElementById("cache-overlay").style.display = "block";
    document.getElementById("menulist").style.display = "none";
    document.getElementById("alertfw").innerHTML =
      '<div class="red">' + msg + "</div>";
    setTimeout(function () {
      document.getElementById("cache-overlay").style.display = "none";
      document.getElementById("alertfw").innerHTML =
        '<div class="red">PS4HostCS a été désactiver</div>';
    }, 6000);
  }
}
/***********************Jailbreak***************************/
function jb_finished() {
  if (main_ret == 179 || main_ret == 0) {
    document.getElementById("cs-loader").style.display = "none";
    document.getElementById("message").innerText =
      "Votre PS4 est maintenant Jailbreak jusqu'au prochain redémarrage.";
    setTimeout(function () {
      document.getElementById("message").innerText = " ";
    }, 4000);
  } else {
    document.getElementById("message").innerText =
      "Le jailbreak a échoué! Cliquez sur Fermer le Navigateur, redémarrez votre PS4 et réessayez.";
  }
}
function load_JB() {
  document.getElementById("message").innerText = "Jailbreak en cours";
  document.getElementById("cs-loader").style.display = "block";
  document.cookie = "exploit=jailbreak";
  setTimeout(function () {
    var element = document.createElement("script");
    element.src = JB("jb");
    document.body.appendChild(element);
  }, 500);
}
/***********************Mirahen***************************/
function mira_finished() {
  setTimeout(function () {
    document.getElementById("message").innerText =
      "Mira + HEN est maintenant démarrer!";
    setTimeout(function () {
      document.getElementById("cs-loader").style.display = "none";
      document.getElementById("message").innerText = " ";
    }, 3000);
  }, 6000);
}

function load_mira() {
  setTimeout(function () {
    document.getElementById("message").innerHTML =
      "Injection de la charge utile";
    document.getElementById("cs-loader").style.display = "block";
    document.cookie = "exploit=mira";
    setTimeout(function () {
      var element = document.createElement("script");
      element.src = SCMIRA("mugiwaramirahen");
      document.getElementsByTagName("head")[0].appendChild(element);
      var element = document.createElement("script");
      element.src = SCMIRA("c-code");
      document.getElementsByTagName("head")[0].appendChild(element);
    }, 1000);
  }, 1000);
}
/***********************Payload***************************/
function payload_finished() {
  document.getElementById("message").innerHTML =
    "La charge utile a bien été injecter";
  setTimeout(function () {
    document.getElementById("message").innerHTML =
      "Démarrage de la la Charge utile";
    document.getElementById("cs-loader").style.display = "none";
    setTimeout(function () {
      document.getElementById("message").innerHTML = "";
      document.getElementById("cs-loader").style.display = "none";
      removeScript(2);
    }, 5000);
    removeScript(2);
  }, 5000);
}
function inject_payload(payload) {
  document.getElementById("message").innerHTML = "Injection de la charge utile";
  document.getElementById("cs-loader").style.display = "block";
  document.cookie = "exploit=payload";
  setTimeout(function () {
    let tab = [payload, "c-code"];
    for (let i = 0; i < tab.length; i++) {
      var element = document.createElement("script");
      if (i == 0) {
        element.src = PAYLOAD(tab[i]);
      } else {
        element.src = SCMIRA(tab[i]);
      }
      document.getElementsByTagName("head")[0].appendChild(element);
    }
  }, 1000);
}
/***********************Binloader***************************/
function binloader_finished() {
  document.getElementById("cs-loader").style.display = "none";
  document.getElementById("message").innerText = "Charge utile bien envoyé...";
  setTimeout(function () {
    document.getElementById("message").innerText =
      "Relancez Binloader pour une autre charge utile";
    setTimeout(function () {
      document.getElementById("message").innerText = " ";
      removeScript(2);
    }, 5000);
  }, 1000);
}
function load_binloader() {
  if (readcookie("exploit") != "null") {
    document.getElementById("message").innerHTML =
      "Vous venez d'activer Mira + Hen !!! Pour utiliser Binloader le Navigateur doit être Quittez par la touche PS d'abords.";
    setTimeout(function () {
      document.getElementById("message").innerHTML =
        "Veuillez Quitter le navigateur entre ces deux opération pour éviter ce message a l'avenir.";
      document.cookie = "exploit=null";
      setTimeout(function () {
        document.getElementById("message").innerHTML = "";
      }, 6000);
    }, 6000);
  } else {
    setTimeout(function () {
      document.getElementById("message").innerHTML =
        "Injection de la charge utile";
      document.getElementById("cs-loader").style.display = "block";

      setTimeout(function () {
        document.getElementById("message").innerText =
          "Utilisez PS4 Injector sur port 9021.Cliquez sur Connecter...";
        document.cookie = "exploit=binloader";
        setTimeout(function () {
          var element = document.createElement("script");
          element.src = SCMIRA("c-code");
          document.getElementsByTagName("head")[0].appendChild(element);
        }, 3000);
      }, 3000);
    }, 1000);
  }
}




var test = false;
function displayFan() {
  let bar = '<div id="fan">';

  console.log(readcookie("fan"));

  switch (readcookie("fan")) {
    case "53":
      level = 1;
      break;
    case "54":
      level = 2;
      break;
    case "55":
      level = 3;
      break;
    case "56":
      level = 4;
      break;
    case "57":
      level = 5;
      break;
    case "58":
      level = 6;
      break;
    case "59":
      level = 7;
      break;
    case "60":
      level = 8;
      break;
    case "61":
      level = 9;
      break;
    case "62":
      level = 10;
      break;
  }

  for (i = 0; i < level; i++) {
    bar += '<button id="' + i + 'btn" class="level"></button>';
  }
  for (i = level; i < 10; i++) {
    bar += '<button id="' + i + 'btn" class="levelclear"></button>';
  }
  bar += '</div><div id="writelevel">' + readcookie("levelTemp") + "°" + "</div>";

  var elem = document.getElementById("fanprogress");
  setInnerHTML(elem, bar);
  setCookieLevel();
}
displayFan();

function setCookieLevel() {
  let fanprogress = document.getElementById("fanprogress");
  let tabLevel = fanprogress.getElementsByTagName("button");
  for (let i = 0; i < tabLevel.length; i++) {
    let id = tabLevel[i].id;
    document.getElementById(id).addEventListener("click", function () {
      switch (id.split("b")[0]) {
        case "0":
          document.cookie = "fan=53";
          document.cookie = "levelTemp=53";
          break;
        case "1":
           document.cookie = "fan=54";
          document.cookie = "levelTemp=54";
          
          break;
        case "2":
           document.cookie = "fan=55";
          document.cookie = "levelTemp=55";
          
          break;
        case "3":
           document.cookie = "fan=56";
          document.cookie = "levelTemp=56";
          
          break;
        case "4":
           document.cookie = "fan=57";
          document.cookie = "levelTemp=57";
          
          break;
        case "5":
           document.cookie = "fan=58";
          document.cookie = "levelTemp=58";
          
          break;
        case "6":
           document.cookie = "fan=59";
          document.cookie = "levelTemp=59";
          
          break;
        case "7":
           document.cookie = "fan=60";
          document.cookie = "levelTemp=60";
          
          break;
        case "8":
           document.cookie = "fan=61";
          document.cookie = "levelTemp=61";
          
          break;
        case "9":
           document.cookie = "fan=62";
          document.cookie = "levelTemp=62";
          
          break;
      }
      if (test == false) {
        test = true;
        displayFan();
        inject_payload("fancontrol");
      } else {
        displayFan();
        test = false;
      }
    });
  }
}
setCookieLevel();
