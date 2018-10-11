<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/"> <!--根模板是必须的-->
    <HTML><HEAD> <TITLE>模板的调用</TITLE></HEAD>
      <BODY>
        <xsl:call-template name ="myTemplate"/>   <!-- 调用模板-->
      </BODY>
    </HTML>
  </xsl:template>
  <xsl:template name="myTemplate" match ="CATALOG/CD" >
 

<!--对所有CD循环处理-->
      <xsl:for-each select="CATALOG/CD"> <!--CATALOG/CD 大小写要和XML文档中一致-->
      <xsl:sort order="descending" select="@ID" />
<p align="center" style="font-weight:bold;"> 
          CD <xsl:value-of select="@ID"/>:  <!--提取CD的ID属性的值-->
        <xsl:value-of select="TITLE"/>    <!--提取每个CD的title-->
</p>
 
 

   </xsl:for-each> 
  </xsl:template>
</xsl:stylesheet>
