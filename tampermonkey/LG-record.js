// ==UserScript==
// @name         洛谷-check-record
// @version      1.0
// @description  洛谷登录页面回车登录
// @author       Fire Humans Skeleton
// @match        https://www.luogu.org/space/show?*
// @grant        none
// ==/UserScript==

window.onload=function()
{
    var uid=parseInt(location.href.replace(/[^0-9|&]/ig,""));
    var ybt=document.getElementsByClassName("am-btn am-btn-sm am-btn-primary");

    var but=document.createElement("a");
    but.setAttribute("href","https://www.luogu.org/recordnew/lists?uid="+uid);
    but.setAttribute("class","am-btn am-btn-sm am-btn-primary");
    but.innerHTML="TA的提交记录";

    ybt[0].parentNode.appendChild(but);
}