using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.OleDb;

namespace AJax
{
    public partial class Province : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                OleDbConnection conn = new OleDbConnection("provider=SQLOLEDB;Data Source=DESKTOP-6LD3FPP;Initial Catalog=master;Uid=test;Pwd=123456");
                conn.Open();
                string sql = string.Format(" select * from Area where parentID = 0");
                OleDbDataAdapter myadapter = new OleDbDataAdapter(sql, conn);
                DataSet myset = new DataSet();
                myadapter.Fill(myset);
                this.Province1.DataSource = myset;
                this.Province1.DataTextField = "name";
                this.Province1.DataValueField = "codeID";
                this.Province1.DataBind();

                conn.Close();
            }
            
        }

        protected void Province1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int id = int.Parse(this.Province1.SelectedItem.Value);
          
            
            OleDbConnection conn1 = new OleDbConnection("provider=SQLOLEDB;Data Source=DESKTOP-6LD3FPP;Initial Catalog=master;Uid=test;Pwd=123456");
            conn1.Open();
            string sql1 = string.Format(" select * from Area where parentID =" + id.ToString());
            OleDbDataAdapter myadapter1 = new OleDbDataAdapter(sql1, conn1);
            DataSet myset1 = new DataSet();
            myadapter1.Fill(myset1);
            this.City1.DataSource = myset1;
            this.City1.DataTextField = "name";
            this.City1.DataValueField = "codeID";
            this.City1.DataBind();

            conn1.Close();
         
        }

        protected void City_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}