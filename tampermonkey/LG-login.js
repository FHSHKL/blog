// ==UserScript==
// @name         洛谷-enter-login
// @version      1.0
// @description  洛谷登录页面回车登录
// @author       Fire Humans Skeleton
// @match        https://www.luogu.org/auth/login
// @grant        none
// ==/UserScript==

window.onload=function()
{
    var login=document.getElementsByClassName("frame lfe-form-sz-middle");
    var log=document.createElement("script");
    log.innerHTML="function log(event){if(event.keyCode === 13){document.getElementsByClassName(\"btn-login lfe-form-sz-middle\")[0].click();}}";
    document.body.appendChild(log);
    for(var i=0;i<login.length;i++)
    {
        login[i].setAttribute('onkeypress','log(event)');
    }
}