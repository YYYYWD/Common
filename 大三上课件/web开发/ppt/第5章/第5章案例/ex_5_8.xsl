<?xml version="1.0" encoding="gb2312"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <HTML><HEAD><TITLE>XML 技术</TITLE></HEAD>
      <BODY BGCOLOR="#00CC66">
        <TABLE border="1" cellspacing="0">
          <TH>姓名</TH><TH>性别</TH>
          <xsl:for-each select="/document/resume [grade &lt; 60]">
            <TR><TD><xsl:value-of select="name"/></TD>
                <TD><xsl:value-of select="sex"/> </TD>
            </TR>
          </xsl:for-each>
        </TABLE> 第个人的生日是<xsl:value-of select="/*/*/birthday"/>
      </BODY>
    </HTML>
  </xsl:template>
</xsl:stylesheet>
