/*
 * @Author: FireHumansSkeleton
 * @Mail: 402146748@qq.com
 * @Website: https://huokulou.tk
 * @Description: LG_scripts
 * @Date: 2019-07-22 08:26:30
 * @LastEditTime: 2019-08-10 10:20:03
 */

function LG_script_init()
{
    const script_version="3.0.0";

    function record_color()
    {
        console.log("LG-record-color*closed*");
    }

    function search_by_name()
    {
        console.log("LG-seanchname");
        document.getElementsByClassName("lg-article lg-index-stat")[0].innerHTML=
        "<h2>题目名搜索</h2><input type='text' class='am-form-field' placeholder='输入要搜索的题目名' name='probnamesearchbox'><p><button class='am-btn am-btn-danger am-btn-sm' name='probnamesearch'>进入题库界面</button>&#32;<button class=\"am-btn am-btn-primary am-btn-sm\" name=\"gotorandom\">随机跳题</button></p>";
        document.getElementsByClassName("am-u-lg-3 am-u-md-4 lg-right")[0].firstElementChild.innerHTML=
        "<h2>用户名搜索</h2><input type='text' class='am-form-field' placeholder='输入要搜索的用户名' name='usernamesearchbox'><p><button class='am-btn am-btn-danger am-btn-sm' name='usernamesearch'>进入用户主页</button></p>";
        function LG_search_name_slove()
        {
            var username=document.getElementsByName("usernamesearchbox")[0].value;
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
            var uprobname=document.getElementsByName("probnamesearchbox")[0].value;
            var pid=uprobname.match(/(poj|cf|sp|u|t|p)?\d*[a-c]?/ig);
            var withp=uprobname.match(/(poj|cf|sp|u|t|p)/ig);
            if(pid==null)
            {
                window.open("https://www.luogu.org/problem/list?keyword="+encodeURIComponent(uprobname));
            }
            else
            {
                pid=pid[0].toLocaleUpperCase();
                if(withp==null)
                {
                    window.open("https://www.luogu.org/problem/P"+pid);
                }
                else
                {
                    window.open("https://www.luogu.org/problem/"+pid);
                }
            }
        }
        $("[name=gotorandom]").click(function () {goto_url('/problemnew/show/P' + (parseInt(Math.random(0, 1) * 4503) + 1000));});
        $("[name=probnamesearch]").onclick=function(){LG_search_prob_slove();};
        $("[name=probnamesearchbox]").keydown(function (e) {if (e.keyCode==13){LG_search_prob_slove();}});
        $("[name=usernamesearch]").onclick=function(){LG_search_name_slove();};
        $("[name=usernamesearchbox]").keydown(function (e) {if (e.keyCode==13){LG_search_name_slove();}});
    };

    function record()
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

    function punch()
    {
        console.log("LG-punch");
        if(document.getElementsByName("punch").length>0)
        {
            document.getElementsByName("punch")[0].click();
        }
    }

    var nurl=location.host+location.pathname;
    console.log("当前版本:"+script_version);
    if((typeof(jQuery)).toLocaleUpperCase()!="undefined")
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
    if(nurl=="www.luogu.org")punch();
    if(nurl=="www.luogu.org/space/show")record();
    if(nurl=="www.luogu.org/")search_by_name();
    if(nurl.match(/www\.luogu\.org\/record\/\d*/ig))setInterval(record_color(),500);
}