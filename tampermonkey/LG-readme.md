# LG-script
## <div style="float:right">洛谷插件合集</div>
## 支持的功能
1. 在用户空间界面添加“TA的提交”按钮
2. 洛谷首页用户名搜索
3. 洛谷首页题目搜索
4. 洛谷登录界面回车登录(官方已完善)
## 即将支持的功能
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
    var s=document.createElement("script");
    s.setAttribute("src","https://huokulou.tk/blog/tampermonkey/LG.js");
    s.setAttribute("onload","LG_script_init()");
    document.body.appendChild(s);
}
```

## 更新
2019/08/03 更新检测jQuery
2019/08/03 更新跳题逻辑，可识别题号，不区分大小写