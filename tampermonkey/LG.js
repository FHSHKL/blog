// ==UserScript==
// @name         洛谷插件合集
// @version      1.0
// @description  洛谷插件合集
// @author       Fire Humans Skeleton
// @match        *://www.luogu.org/*
// @grant        none
// ==/UserScript==

function LG_search()
{
    console.log("LG-search");
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

function LG_record()
{
    console.log("LG-record");
    var uid=parseInt(location.href.replace(/[^0-9|&]/ig,""));
    var ybt=document.getElementsByClassName("am-btn am-btn-sm am-btn-primary");

    var but=document.createElement("a");
    but.setAttribute("href","https://www.luogu.org/recordnew/lists?uid="+uid);
    but.setAttribute("class","am-btn am-btn-sm am-btn-primary");
    but.setAttribute("target","_blank");
    but.innerHTML="TA的提交";

    ybt[0].parentNode.appendChild(but);
}

function get_new(nurl)
{
    if(nurl=="www.luogu.org/problemnew/lists")location.href="https://www.luogu.org/fe/problem/list";
    if(nurl.search("problemnew/show")>-1&&nurl.search("fe/problem")==-1)location.href=location.href.replace("problemnew/show","fe/problem");
    if(nurl.search("recordnew/show")>-1&&nurl.search("fe/record")==-1)location.href=location.href.replace("recordnew/show","fe/record");
}

window.onload=function()
{
    var nurl=location.host+location.pathname;
    console.log(nurl);
    if(nurl=="www.luogu.org/recordnew/lists")LG_search();
    if(nurl=="www.luogu.org/space/show")LG_record();
    get_new(nurl);
}

/*
recordnew/show
fe/record
*/