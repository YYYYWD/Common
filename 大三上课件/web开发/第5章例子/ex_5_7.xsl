<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <HTML><HEAD><TITLE>模板的调用</TITLE></HEAD>
      <BODY>
        <xsl:apply-templates select ="CATALOG"/>
      </BODY>
    </HTML>
  </xsl:template>
  <xsl:template match ="CATALOG">
    <p align="center" style="font-weight:bold;">
      <xsl:for-each select="./CD">
        CD <xsl:value-of select="@ID"/>:
        <xsl:value-of select="TITLE"/>
      </xsl:for-each>
    </p>
  </xsl:template>
</xsl:stylesheet>
