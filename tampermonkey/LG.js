function LG_script_init()
{

    const script_version="7.4.105";

    function chat()
    {
        console.log("LG-chat");
        var s=document.createElement("style");
        s.innerHTML=".message{word-break:break-all;}";
        document.head.appendChild(s);
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

    function search_by_name()
    {
        console.log("LG-seanchname");
        document.getElementsByClassName("lg-article lg-index-stat")[0].innerHTML=
        "<h2>题目名搜索</h2><p><input type='text' class='am-form-field' placeholder='输入要搜索的题目名' name='probnamesearchbox'></input></p><button class='am-btn am-btn-danger am-btn-sm' name='probnamesearch'>进入题库界面</button>&#32;<button class=\"am-btn am-btn-primary am-btn-sm\" name=\"gotorandom\">随机跳题</button>";
        document.getElementsByClassName("am-u-lg-3 am-u-md-4 lg-right")[0].firstElementChild.innerHTML=
        "<h2>用户名搜索</h2><p><input type='text' class='am-form-field' placeholder='输入要搜索的用户名' name='usernamesearchbox'></input></p><button class='am-btn am-btn-danger am-btn-sm' name='usernamesearch'>进入用户主页</button>&#32;<div class=\"users_cd\" id=\"user_list\"></div>";
        function LG_search_name_slove()
        {
            var username=document.getElementsByName("usernamesearchbox")[0].value;
            $.get(
                "https://www.luogu.com.cn/fe/api/user/search?keyword="+username,
                function (data)
                {
                    if(data["users"][0]==null)
                    {
                        show_alert("找不到用户");
                        return;
                    }
                    var tarid=data["users"][0].uid;
                    window.open("https://www.luogu.com.cn/user/"+tarid);
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
                window.open("https://www.luogu.com.cn/problem/list?keyword="+encodeURIComponent(uprobname));
            }
            else
            {
                pid=pid[0].toLocaleUpperCase();
                if(withp==null)
                {
                    window.open("https://www.luogu.com.cn/problem/P"+pid);
                }
                else
                {
                    window.open("https://www.luogu.com.cn/problem/"+pid);
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
        console.log("LG-record-coding");
        if(location.href.match(/\/user\/121910/ig)){
            document.getElementsByClassName("user-header-top")[0].style=`background-image: url("https://i.loli.net/2019/08/02/5d43841d41ed869379.jpg");`;
        }
        return;
        var uid=parseInt(location.href.replace(/[^0-9|&]/ig,""));
        var ybt=document.getElementsByClassName("dropdown")[0];

        var but=document.createElement("a");
        but.setAttribute("href","https://www.luogu.com.cn/record/list?user="+uid);
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
            jq.setAttribute("src","https://firehumansskeleton.github.io/static/js/jquery.js");
            document.head.appendChild(jq);
            console.log("jQuery已加载");
        }
        var to_do_list={
            "www.luogu.com.cn":"punch();search_by_name();background();",
            "www.luogu.com.cn/":"punch();search_by_name();background();",
            "www.luogu.com.cn":"punch();search_by_name();background();",
            "www.luogu.com.cn/":"punch();search_by_name();background();",
            "match_0":"record();",
            "match_1":"chat();"
        }
        var match_list=[
            /www\.luogu.+\/user\//ig,
            /www\.luogu.+\/chat/ig
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
