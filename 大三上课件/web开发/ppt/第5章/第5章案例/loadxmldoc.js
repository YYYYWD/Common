function loadXMLDoc(dname) {  //创建XML DOM Document 对象xmlDoc
var xmlDoc;
if (window.ActiveXObject)  // 针对IE 浏览器
xmlDoc=new ActiveXObject("Microsoft.XMLDOM");  
// 针对 Mozilla, Firefox, Opera 等浏览器
else if (document.implementation && document.implementation.createDocument) 
xmlDoc=document.implementation.createDocument("","",null);
else 
alert('Your browser cannot handle this script');
xmlDoc.async=false;
xmlDoc.load(dname); //加载XML文档到Document对象
if (xmlDoc.parseError.errorCode!=0) alert(("You have error:" & xmlDoc.parseError.reason));
return(xmlDoc);
}
