<?xml version="1.0" encoding="gb2312"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <HTML>
      <HEAD><TITLE>ѧ��������</TITLE>
        <STYLE>
          .title{font-size:15pt; font-weight:bold; color:blue }
          .name{color:red}
          table {background-image: url("images/bg.jpg")}
        </STYLE>
      </HEAD>
      <BODY>
        <P class="title" >ѧ��������</P>
        <xsl:apply-templates select="roster"/>
      </BODY>
    </HTML>
  </xsl:template>

  <xsl:template match="roster">
    <TABLE BORDER="1">
      <THEAD>
        <TD><B>����</B></TD>
        <TD><B>����</B></TD>
        <TD><B>����</B></TD>
        <TD><B>�绰</B></TD>
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
