<!--
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-03 08:32:29
 * @lastTime: 2019-08-21 15:40:39
 * @LastAuthor: Please set LastEditors
 -->
# LG-script
## <div style="float:right">洛谷插件合集</div>
## 支持的功能
1. 自动更新脚本
2. 在用户空间界面添加“TA的提交”按钮
3. 洛谷首页用户名搜索
4. 洛谷首页题目搜索
5. 洛谷自动打卡
6. ~~洛谷登录界面回车登录~~
## 即将支持的功能
1. 支持使用旧版洛谷评测结果颜色
## 使用方法
1. 下载并安装油猴插件([wall](http://www.tampermonkey.net/)&[nowall](https://blog.csdn.net/vermont_/article/details/84781871))
2. 点击右上角油猴图标
3. 进入管理面板
4. 点击“已安装脚本左侧加号”新建用户脚本
5. 清空输入框后粘贴如下代码
6. ctrl^s或点击上方文件按钮再点击保存
7. 安装完成
## 代码
```js
// ==UserScript==
// @name         洛谷插件合集
// @version      1.0
// @description  洛谷插件合集
// @author       Fire Humans Skeleton
// @match        *://www.luogu.org/*
// @grant        none
// ==/UserScript==
window.onload=function()
{
    var local=localStorage.getItem("LG_script_version");
    if(local)
    {
        var s=document.createElement("script");
        s.setAttribute("name","LG_script");
        s.innerHTML=localStorage.getItem("LG_script");
        document.body.appendChild(s);
        LG_load_from_local();
    }
    var scr=document.createElement("script");
    scr.setAttribute("src","http://localhost:8080/tampermonkey/lg.js");
    scr.setAttribute("onload","LG_script_init()");
    scr.setAttribute("name","LG_script");
    document.body.appendChild(scr);
}
```

## 更新
```
2019/08/21 修复多次加载bug
2019/08/21 优化加载速度
2019/08/15 修改用于匹配题目编号的正则表达式
2019/08/11 添加识别UVA与AT开头题目
2019/08/11 修改调用功能函数方式
2019/08/10 修正跳题逻辑
2019/08/10 自动使用旧版洛谷评测结果颜色
2019/08/10 修改跳题按钮位置，增加随机跳题按钮
2019/08/10 修改跳题逻辑，可识别CodeForces题号
2019/08/10 使用局部函数，防止变量重名
2019/08/10 修复无法私信bug
2019/08/07 更新自动打卡
2019/08/03 更新检测jQuery
2019/08/03 更新跳题逻辑，可识别题号，不区分大小写
```

## coder
```
LG_wxb-FireHumansSkeleton
LG_wsc-2018小绿
```