<%-- 
    Document   : withdraw
    Created on : 31 Oct, 2019, 3:09:02 PM
    Author     : wad15
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Withdraw</title>
    </head>
    <body>
        <%@ page import = "java.sql.*" %>
        <%
            String username = (String)session.getAttribute("username");
            String amount = request.getParameter("amount");
            if(username == null){
                response.sendRedirect("index.html");
            }
            
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection("jdbc:postgresql://localhost:5432/bank1", "postgres", "root");
            Statement st = con.createStatement();
            int i = st.executeUpdate("update users set balance = balance -"+amount+" where username = '"+username+"';");
        %>
        <br>
        <a href="loggedin.jsp">Go back</a>
    </body>
</html>