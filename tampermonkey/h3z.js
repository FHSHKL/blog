/*
 $-Author: FireHumansSkeleton
 $-since: 2019-08-20 14:48:12
 $-lastTime: 2019-08-20 15:03:14
 $-Mail: 402146748@qq.com
*/

function h3z_script_init()
{
    const script_version="4.3.4";

    function titlecol()
    {
        var s=document.getElementsByClassName("navbar navbar-default")[0];
        s.setAttribute("style","background-color:#000;color:#fff;background-image:linear-gradient(to bottom, #000 0px, #000 100%);");
        s=document.getElementById("navbar");
    }

    var nurl=location.host+location.pathname;
    console.log("当前版本:"+script_version);
    if((typeof(jQuery)).toLocaleUpperCase()!="undefined")
    {
        console.log("jQuery已加载");
    }
    else
    {
        console.log("未检测到jquery");
        var jq=document.createElement("script");
        jq.setAttribute("src","https://huokulou.tk/static/js/jquery.js");
        document.head.appendChild(jq);
        console.log("jquery已加载");
    }
    titlecol();
}