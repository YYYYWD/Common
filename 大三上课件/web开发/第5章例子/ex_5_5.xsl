<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <body>
        <table border="2" bgcolor="yellow">
          <tr><th>Title</th> <th>Artist</th><th>price</th></tr>
          <xsl:for-each select="CATALOG/CD"> <!--��XML�ĵ����и�Ԫ���µ�CDԪ��ѭ��-->
            <tr>
              <td><xsl:value-of select="TITLE"/></td>  <!--��ȡTITLEԪ�ص�ֵ-->
              <td><xsl:value-of select="ARTIST"/></td> <!--��ȡARTISTԪ�ص�ֵ-->

              <td><xsl:value-of select="PRICE"/></td> <!--��ȡpriceԪ�ص�ֵ-->
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
