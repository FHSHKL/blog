/*
 $-Author: FireHumansSkeleton
 $-since: 2019-07-22 08:26:30
 $-lastTime: 2019-09-16 16:33:40
 $-Mail: 402146748@qq.com
*/

function LG_script_init()
{

    const script_version="7.2.93";

    function message()
    {
        console.log("LG-message");
        var tim=setInterval(function()
        {
            var height=window.innerHeight-document.getElementsByClassName("wrapper wrapped lfe-body header-layout narrow")[0].scrollHeight;
            var s=document.getElementsByClassName("lg-message-content")[0];
            if(s==undefined)
            {
                return;
            }
            s=document.getElementsByClassName("am-input-group am-input-group-sm am-input-group-primary")[0];
            s.style.top="16px";
            s.style.position="sticky";
            s=document.getElementsByClassName("lg-contacts")[0];
            s.style.overflow="unset";
            s.style.height="unset";
            s=document.getElementsByClassName("am-u-md-7")[0].getElementsByClassName("lg-small")[0];s.parentNode.removeChild(s);
            document.getElementsByClassName("am-u-md-7")[0].getElementsByClassName("lg-article")[0].style.height="100%";
            document.getElementsByClassName("lg-message-content")[0].style.height="85%";
            s=document.getElementsByClassName("am-u-md-5")[0];
            s.style.height=height+"px";
            s.style.overflowX="hidden";
            s.style.overflowY="auto";
            s=document.getElementsByClassName("am-u-md-7")[0];
            s.style.height=height+"px";
            
            clearInterval(tim);
        },100);
    }

    function background()
    {
        console.log("LG-background");
        var bac=document.getElementsByClassName("background")[0];
        bac.style.zIndex=1;
        var s=bac.parentNode.children[1];
        for(var i=0;i<3;i++)
        {
            s.children[i].style.zIndex=2;
        }

        s=document.getElementsByClassName("user-nav")[0];
        s.style.backgroundColor="rgb(255,255,255,.5)";
        s.style.padding="5px";
        s.style.borderRadius="10px";

        s=document.getElementsByClassName("header-link color-none");
        for(var i=0;i<2;i++)
        {
            s[i].style.backgroundColor="rgb(255,255,255,.5)";
            s[i].style.padding="5px";
            s[i].style.borderRadius="10px";
        }
    }

    function get_user_list()
    {
        console.log("LG-users");
        var sty_box=document.createElement("style");
        sty_box.innerHTML=".users_cd{position: absolute;display: inline-flex;max-height:100px;overflow-y:scroll;}"+
        ".users_cd::-webkit-scrollbar{display: none;}"+
        ".users_cd > div{display: none;course:pointer;}"+
        ".users_cd > span{background-color:#0e90d2;color:#fff;font-size: 1.4rem;padding:6px 14px 6px 14px;text-align: center;border-radius: 5px;}"+
        ".users_cd:hover{border:1px solid #ccc;}"+
        ".users_cd:hover > span{display: none;}"+
        ".users_cd:hover > div{display: block;}";
        document.head.appendChild(sty_box);
        var uid_num=(localStorage.getItem("uid_num")*1)||(0);
        var s=document.getElementById("user_list");
        for(var i=0;i<uid_num;i++)
        {
            var ch=document.createElement("div");
            var now=localStorage.getItem("uid_"+i);
            ch.innerHTML=now;
            s.appendChild(ch);
        }
    }

    function search_by_name()
    {
        console.log("LG-seanchname");
        document.getElementsByClassName("lg-article lg-index-stat")[0].innerHTML=
        "<h2>题目名搜索</h2><p><input type='text' class='am-form-field' placeholder='输入要搜索的题目名' name='probnamesearchbox'></input></p><button class='am-btn am-btn-danger am-btn-sm' name='probnamesearch'>进入题库界面</button>&#32;<button class=\"am-btn am-btn-primary am-btn-sm\" name=\"gotorandom\">随机跳题</button>";
        document.getElementsByClassName("am-u-lg-3 am-u-md-4 lg-right")[0].firstElementChild.innerHTML=
        "<h2>用户名搜索</h2><p><input type='text' class='am-form-field' placeholder='输入要搜索的用户名' name='usernamesearchbox'></input></p><button class='am-btn am-btn-danger am-btn-sm' name='usernamesearch'>进入用户主页</button>&#32;<div class=\"users_cd\" id=\"user_list\"><span>常用uid</span></div>";
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
            var pid=uprobname.match(/(uva|at|poj|cf|sp|u|t|p)?\d+[a-z]?/ig);
            var withp=uprobname.match(/(uva|at|poj|cf|sp|u|t|p)/ig);
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
        $("[name=gotorandom]").click(function () {window.open('/problemnew/show/P' + (parseInt(Math.random(0, 1) * 4503) + 1000));});
        $("[name=probnamesearch]")[0].onclick=function(){LG_search_prob_slove();};
        $("[name=probnamesearchbox]").keydown(function (e) {if (e.keyCode==13){LG_search_prob_slove();}});
        $("[name=usernamesearch]")[0].onclick=function(){LG_search_name_slove();};
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

    function init()
    {
        if(document.getElementsByName("LG_script").length>1)
        {
            return;
        }
        var nurl=location.host+location.pathname;
        console.log("LG-version:"+script_version);
        if((typeof(jQuery)).toLocaleUpperCase()!="undefined")
        {
            console.log("jQuery已加载");
        }
        else
        {
            console.log("未检测到jQuery");
            var jq=document.createElement("script");
            jq.setAttribute("src","https://huokulou.tk/static/js/jquery.js");
            document.head.appendChild(jq);
            console.log("jQuery已加载");
        }
        var to_do_list={
            "www.luogu.org":"punch();search_by_name();background();get_user_list();",
            "www.luogu.org/":"punch();search_by_name();background();get_user_list();",
            "www.luogu.com.cn":"punch();search_by_name();background();get_user_list();",
            "www.luogu.com.cn/":"punch();search_by_name();background();get_user_list();",
            "match_0":"message();",
            "match_1":"record();"
        }
        var match_list=[
            /action=message/ig,
            /www\.luogu.+\/space\/show/ig
        ]
        for(var i=0;i<match_list.length;i++)
        {
            if(location.href.match(match_list[i]))
            {
                eval(to_do_list["match_"+i]);
            }
        }
        eval(to_do_list[nurl]);
    }

    function updata_script()
    {
        console.log("LG-updata");
        localStorage.setItem("LG_script_version",script_version);
        localStorage.setItem("LG_script",LG_script_init.toString().replace("LG_script_init","LG_load_from_local"));
    }

    function check_version()
    {
        var version=localStorage.getItem("LG_script_version");
        
        if(version!=null)
        {
            if(version==script_version)
            {
                init();
            }
            else
            {
                updata_script();
            }
        }
        else
        {
            updata_script();
            init();
        }
    }

    check_version();
    
}
