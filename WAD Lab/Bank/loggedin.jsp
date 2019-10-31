<%-- 
    Document   : loggedin
    Created on : 31 Oct, 2019, 2:19:24 PM
    Author     : wad15
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%
            
          String username = (String)session.getAttribute("username");
          if(username == null){
              response.sendRedirect("index.html");
          }
          
        %>
        <table>
        <form method="POST" action="deposit.jsp">
            <tr>
                <td><input type="text" name="amount"></td>
                <td><input type="submit" value="Deposit"></td>
            </tr>
        </form>
        <form method="POST" action="withdraw.jsp">
            <tr>
                <td><input type="text" name="amount"></td>
                <td><input type="submit" value="Withdraw"></td>
            </tr>
        </form>
        <form method="POST" action="checkbalance.jsp">
            <tr>
                <td><input type="submit" value="Check Balance"></td>
            </tr>
        </form>
        </table>
        <p>You have successfully logged in!</p>
        <a href="logout.jsp">Log out</a>
    </body>
</html>
