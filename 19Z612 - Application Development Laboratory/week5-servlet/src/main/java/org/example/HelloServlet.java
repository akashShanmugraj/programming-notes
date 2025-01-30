package org.example;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * A simple servlet that generates and displays a random Image
 */
@WebServlet("/hello")
public class HelloServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // Array of Images to choose from
        String[] Images = {
                "https://github.com/user-attachments/assets/2af4ddfb-9309-46ac-bf87-035417c6ed65",
                "https://github.com/user-attachments/assets/805d0228-0caa-4127-9cf7-289b651bf7fc",
                "https://github.com/user-attachments/assets/a6ac6bbe-c8a0-444d-a4e0-5ddfb809c51a",
                "https://github.com/user-attachments/assets/d076f4cc-9d34-4e4a-9e7f-9401c6d0283d"
        };
        // Generate a random index to select a Image
        int randomIndex = (int) (Math.random() * Images.length);
        String randomImage = Images[randomIndex]; // Select a random Image
        // Set the content type of the response to HTML
        response.setContentType("text/html");
        // Write the response to display the random Image
        response.getWriter().println("<html>");
        response.getWriter().println("<head><title>Random Image</title></head>");
        response.getWriter().println("<body>");
        response.getWriter().println("<h1>Random Image</h1>");
        response.getWriter().println("<img src=\"" + randomImage + "\" alt=\"Random Image\" />");
        response.getWriter().println("</body>");
        response.getWriter().println("</html>");
    }
}