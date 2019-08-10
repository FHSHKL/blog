/*
 * @Author: FireHumansSkeleton
 * @Mail: 402146748@qq.com
 * @Website: https://huokulou.tk
 * @Description: LG_scripts
 * @Date: 2019-07-22 08:26:30
 * @LastEditTime: 2019-08-10 09:49:41
 */

function LG_script_init()
{
    const script_version="3.0.0";

    function new_recore_color()
    {
        var flagColorMap = {
            0: "background-color: #2E468C;",
            1: "background-color: #3498db;",
            2: "background-color: #f1c40f;",
            3: "background-color: #2E468C;",
            4: "background-color: #2E468C;",
            5: "background-color: #2E468C;",
            6: "background-color: #e74c3c;",
            7: "background-color: #8e44ad;",
            12: "background-color: #5eb95e;",
            14: "background-color: #e74c3c;",
            21: "background-color: #5eb95e;",
            22: "background-color: #e74c3c;",
            23: "background-color: #2E468C;"
        };
        var record=window._feInjection.currentData.record.detail.testcases;
        var oldrecord=document.getElementsByClassName("test-case-wrap")[0].children;
        for(var i=0;i<oldrecord.length;i++)
        {
            oldrecord[i].children[0].style=flagColorMap[record[i+1].status];
        }
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
    console.log("当前地址:"+nurl);
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
    if(nurl.match(/www\.luogu\.org\/record\/\d*/ig))new_recore_color();
}