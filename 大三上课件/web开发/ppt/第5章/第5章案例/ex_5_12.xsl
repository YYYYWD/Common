<?xml version="1.0" encoding="gb2312"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <HTML>
      <HEAD><TITLE>学生花名册</TITLE>
        <STYLE>
          .title{font-size:15pt; font-weight:bold; color:blue }
          .name{color:red}
          table {background-image: url("images/bg.jpg")}
        </STYLE>
      </HEAD>
      <BODY>
        <P class="title" >学生花名册</P>
        <xsl:apply-templates select="roster"/>
      </BODY>
    </HTML>
  </xsl:template>

  <xsl:template match="roster">
    <TABLE BORDER="1">
      <THEAD>
        <TD><B>姓名</B></TD>
        <TD><B>籍贯</B></TD>
        <TD><B>年龄</B></TD>
        <TD><B>电话</B></TD>
      </THEAD>
      <xsl:for-each select="student">
        <xsl:sort order="ascending" select="name"/>
        <TR>
          <TD> <B><xsl:value-of select="name"/></B>  </TD>
          <TD>   <xsl:value-of select="origin"/>     </TD>
          <TD>   <xsl:value-of select="age"/>        </TD>
          <TD>   <xsl:value-of select = "telephone"/></TD>
        </TR>
      </xsl:for-each>
    </TABLE>
  </xsl:template>
</xsl:stylesheet>
