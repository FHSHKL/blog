// ==UserScript==
// @name         洛谷插件合集
// @version      1.0
// @description  洛谷插件合集
// @author       Fire Humans Skeleton
// @match        *://www.luogu.org/*
// @grant        none
// ==/UserScript==

function LG_record()
{
    console.log("LG-record");
    var uid=parseInt(location.href.replace(/[^0-9|&]/ig,""));
    var ybt=document.getElementsByClassName("am-btn am-btn-sm am-btn-primary");

    var but=document.createElement("a");
    but.setAttribute("href","https://www.luogu.org/record/list?user="+uid);
    but.setAttribute("class","am-btn am-btn-sm am-btn-primary");
    but.setAttribute("target","_blank");
    but.innerHTML="TA的提交";

    ybt[0].parentNode.appendChild(but);
}

window.onload=function()
{
    var nurl=location.host+location.pathname;
    console.log(nurl);
    if(nurl=="www.luogu.org/space/show")LG_record();
}

/*
recordnew/show
fe/record

get new lg

*/