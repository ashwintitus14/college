/*
Copyright (C) 2019 wad15

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.sql.*;

/**
 *
 * @author wad15
 */
@WebServlet(urlPatterns = {"/register"})
public class register extends HttpServlet {
    
    Connection connection;
    String url = "jdbc:postgresql://localhost:5432/ex1";
    String dbusername = "postgres";
    String dbpassword = "root";
  
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //processRequest(request, response);
        
        PrintWriter out = response.getWriter(); 
        
        try {
            Class.forName("org.postgresql.Driver");
        } catch(ClassNotFoundException e) {
            out.println(e.getMessage());
        }
        
        try {
            String name, user, pass;
            name = request.getParameter("name");
            user = request.getParameter("username");
            pass = request.getParameter("pass");
        
            connection = DriverManager.getConnection(url, dbusername, dbpassword);
            //out.println("Connected");
            Statement stmt = connection.createStatement();
            int i = stmt.executeUpdate("INSERT INTO login_data(name, uname, password) VALUES ('"+name+"','"+user+"','"+pass+"');");
            //out.println(i);
            connection.close();
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<h2>User created successfully!</h2>");
            out.println("<a href='index.html'>Go back to login page</a>");
            out.println("</html>");
            
            
        } catch(SQLException ex) {
            out.println(ex.getMessage());
            
        }
        //Statement stmt = connection.createStatement();
        //ResultSet rs = stmt.executeQuery("select * from ex1;");
              
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
