// ==UserScript==
// @name         洛谷-search-myself
// @version      1.0
// @description  洛谷记录搜索
// @author       Fire Humans Skeleton
// @match        https://www.luogu.org/recordnew/lists*
// @grant        none
// ==/UserScript==

window.onload=function()
{
    var but=document.createElement("button");
    but.setAttribute("name","searchme");
    but.setAttribute("class","am-btn am-btn-danger");
    but.innerHTML="ME!";
    but.setAttribute("onclick","search_me()");

    var bro=document.getElementsByName("recordsearch")[0];
    bro.parentNode.appendChild(but);


    var log=document.createElement("script");
    log.innerHTML="function search_me(){var uid=document.getElementsByTagName('html')[0].innerHTML.match(/uid=[0-9]+/)[0].replace(/uid=/i,'');var ui=document.getElementsByName(\"uid\")[0];ui.nodeValue=uid;ui.value=uid;var submit=document.getElementsByName(\"recordsearch\")[0];submit.click();}";
    document.body.appendChild(log);

}