<%-- 
    Document   : login
    Created on : 31 Oct, 2019, 1:56:02 PM
    Author     : wad15
--%>

<%@page import="java.sql.DriverManager"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Validate user</title>
    </head>
    <body>
        <%@ page import ="java.sql.*" %>
        <%
          String username = request.getParameter("username");
          String password = request.getParameter("password");
          
          Class.forName("org.postgresql.Driver");
          Connection con = DriverManager.getConnection("jdbc:postgresql://localhost:5432/bank1", "postgres", "root");
          Statement st = con.createStatement();
          ResultSet rs;
          rs = st.executeQuery("select * from users where username='"+username+"'and password='"+password+"';");
          if(rs.next()){
              session.setAttribute("username", username);
              response.sendRedirect("loggedin.jsp");
          }
          else{
              response.sendRedirect("index.html");
          }
          
        %>
    </body>
</html>
