const version=1;

// ==UserScript==
// @name         洛谷插件合集
// @version      1.0
// @description  洛谷插件合集
// @author       Fire Humans Skeleton
// @match        *://www.luogu.org/*
// @require      https://huokulou.tk/static/js/jquery.js
// @grant        none
// ==/UserScript==

function LG_searchname()
{
    console.log("LG-seanchname");
    document.getElementsByClassName("am-u-lg-3 am-u-md-4 lg-right")[0].firstElementChild.innerHTML=
    "<h2>用户名搜索</h2><input type='text' class='am-form-field' placeholder='输入要搜索的用户名' id='usernamesearchbox'><p><button class='am-btn am-btn-danger am-btn-sm' id='usernamesearch'>进入用户主页</button></p>"+
    "<h2>题目名搜索</h2><input type='text' class='am-form-field' placeholder='输入要搜索的题目名' id='probnamesearchbox'><p><button class='am-btn am-btn-danger am-btn-sm' id='probnamesearch'>进入题库页面</button></p>";
    function searchname()
    {
        var username=document.getElementById("usernamesearchbox").value;
        $.get(
            "/space/ajax_getuid?username="+username,
            function (data)
            {
                var arr = eval('(' + data + ')');
                if(arr['code']=="404")
                {
                    show_alert("找不到用户");
                    return;
                }
                var tarid=arr['more']['uid'];

                window.open("https://www.luogu.org/space/show?uid="+tarid);
            }
        );
    }
    function searchprob()
    {
        var uprobname=document.getElementById("probnamesearchbox").value;
        window.open("https://www.luogu.org/problem/list?keyword="+encodeURIComponent(uprobname));
    }
    document.getElementById("probnamesearch").onclick=function(){searchprob();};
    $(document.getElementById("probnamesearchbox")).keydown(function (e) {if (e.keyCode==13){searchprob();}});
    document.getElementById("usernamesearch").onclick=function(){searchname();};
    $(document.getElementById("usernamesearchbox")).keydown(function (e) {if (e.keyCode==13){searchname();}});
};

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

function LG_login()
{
    console.log("LG-login");
    var s=document.getElementsByClassName("frame lfe-form-sz-middle");
    for(var i=0;i<s.length;i++)
    {
        var now=s[i];
        now.onkeypress=function doit(e){if(e.keyCode==13){document.getElementsByClassName("btn-login lfe-form-sz-middle")[0].click();}};
    }
}

window.onload=function()
{
    var nurl=location.host+location.pathname;
    console.log(nurl);
    if(nurl=="www.luogu.org/space/show")LG_record();
    if(nurl=="www.luogu.org/")LG_searchname();
    if(nurl=="www.luogu.org/auth/login")LG_login();
}

/*
recordnew/show
fe/record

get new lg

*/