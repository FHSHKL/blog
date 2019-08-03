/*
 * @Author: FireHumansSkeleton
 * @Mail: 402146748@qq.com
 * @Website: https://huokulou.tk
 * @Description: LG_scripts
 * @Date: 2019-07-22 08:26:30
 * @LastEditTime: 2019-08-03 08:59:46
 */

 const version="2.0.0";

function LG_script_search_by_name()
{
    console.log("LG-seanchname");
    document.getElementsByClassName("am-u-md-9")[0].style.width="100%";
    var s=document.getElementsByClassName("am-u-md-3")[0];
    s.parentNode.removeChild(s)
    document.getElementsByClassName("am-u-lg-3 am-u-md-4 lg-right")[0].firstElementChild.innerHTML=
    "<h2>用户名搜索</h2><input type='text' class='am-form-field' placeholder='输入要搜索的用户名' id='usernamesearchbox'><p><button class='am-btn am-btn-danger am-btn-sm' id='usernamesearch'>进入用户主页</button></p>"+
    "<h2>题目名搜索</h2><input type='text' class='am-form-field' placeholder='输入要搜索的题目名' id='probnamesearchbox'><p><button class='am-btn am-btn-danger am-btn-sm' id='probnamesearch'>进入题库页面</button></p>";
    function LG_search_name_slove()
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
    function LG_search_prob_slove()
    {
        var uprobname=document.getElementById("probnamesearchbox").value;
        var pid=uprobname.match(/(poj|cf|sp|u|t|p)?[0-9]\d*/ig);
        var withp=uprobname.match(/(poj|cf|sp|u|t|p)/ig);
        if(pid==null)
        {
            window.open("https://www.luogu.org/problem/list?keyword="+encodeURIComponent(uprobname));
        }
        else
        {
            if(withp==null)
            {
                window.open("https://www.luogu.org/problem/P"+pid[0]);
            }
            else
            {
                window.open("https://www.luogu.org/problem/"+pid[0]);
            }
        }
    }
    document.getElementById("probnamesearch").onclick=function(){LG_search_prob_slove();};
    $(document.getElementById("probnamesearchbox")).keydown(function (e) {if (e.keyCode==13){LG_search_prob_slove();}});
    document.getElementById("usernamesearch").onclick=function(){LG_search_name_slove();};
    $(document.getElementById("usernamesearchbox")).keydown(function (e) {if (e.keyCode==13){LG_search_name_slove();}});
};

function LG_script_record()
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

function LG_script_init()
{
    var nurl=location.host+location.pathname;
    console.log("当前版本:"+version);
    console.log("当前地址:"+nurl);
    if(jQuery)
    {
        console.log("jquery已加载");
    }
    else
    {
        console.log("未检测到jquery");
        var jq=document.createElement("script");
        jq.setAttribute("src","https://huokulou.tk/static/js/jquery.js");
        document.head.appendChild(jq);
        console.log("jquery已加载");
    }
    if(nurl=="www.luogu.org/space/show")LG_script_record();
    if(nurl=="www.luogu.org/")LG_script_search_by_name();
}