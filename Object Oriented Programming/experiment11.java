public class experiment11 {
    public static void main(String[] args) {

        // String Concatenation within Strings example
        System.out.println("1. String Concatenation within Strings example\n");
        String str1 = "Hello";
        String str2 = "World";
        String str3 = str1 + str2;
        System.out.println(str3);

        System.out.println();

        // String Concatenation with other data types example
        System.out.println("2. String Concatenation with other data types example\n");
        String str4 = "Hello";
        int num = 123;
        String str5 = str4 + num;
        System.out.println(str5);

        System.out.println();

        // String Conversion and toString() method example
        System.out.println("3. String Conversion and toString() method example\n");
        int num1 = 123;
        String str6 = String.valueOf(num1);
        System.out.println(str6);

        System.out.println();

        System.out.println("4. Character Extraction\n");
        // charAt() method example

        System.out.println("charAt() method example");

        String str7 = "Hello";
        char ch = str7.charAt(0);
        System.out.println(ch);

        System.out.println();

        // getChars() method example

        System.out.println("getChars() method example");

        String str8 = "Hello";
        char[] ch1 = new char[10];
        str8.getChars(0, 3, ch1, 0);
        System.out.println(ch1);

        System.out.println();

        // getBytes() method example

        System.out.println("getBytes() method example");

        String str9 = "Hello";
        byte[] b = str9.getBytes();
        for (int i = 0; i < b.length; i++) {
            System.out.println(b[i]);
        }

        System.out.println();

        // toCharArray() method example

        System.out.println("toCharArray() method example");

        String str10 = "Hello";
        char[] ch2 = str10.toCharArray();
        for (int i = 0; i < ch2.length; i++) {
            System.out.println(ch2[i]);
        }

        System.out.println();

        System.out.println("5. String Comparison \n");

        // equals() and equalsIgnoreCase() method example

        System.out.println("equals() and equalsIgnoreCase() method example");

        String str11 = "Hello";
        String str12 = "Hello";
        String str13 = "hello";
        System.out.println(str11.equals(str12));
        System.out.println(str11.equals(str13));
        System.out.println(str11.equalsIgnoreCase(str13));

        // regionMatches() method example

        System.out.println("regionMatches() method example");

        String str14 = "Hello";
        String str15 = "Hello World";
        System.out.println(str14.regionMatches(0, str15, 0, 5));
        System.out.println(str14.regionMatches(0, str15, 6, 5));

        System.out.println();

        // startsWith() and endsWith() method example

        System.out.println("startsWith() and endsWith() method example");

        String str16 = "Hello";
        System.out.println(str16.startsWith("He"));
        System.out.println(str16.endsWith("lo"));

        System.out.println();

        // equals() and == operator example

        System.out.println("equals() and == operator example");

        String str17 = "Hello";
        String str18 = "Hello";
        String str19 = new String("Hello");
        System.out.println(str17 == str18);
        System.out.println(str17 == str19);
        System.out.println(str17.equals(str18));

        System.out.println();

        // compareTo() method example

        System.out.println("compareTo() method example");

        String str20 = "Hello";
        String str21 = "Hello";
        String str22 = "hello";
        System.out.println(str20.compareTo(str21));
        System.out.println(str20.compareTo(str22));
        System.out.println(str22.compareTo(str20));

        System.out.println();

        // Searching Strings

        System.out.println("6. Searching Strings\n");

        String str23 = "Hello World";
        System.out.println(str23.indexOf('o'));
        System.out.println(str23.indexOf('o', 5));
        System.out.println(str23.lastIndexOf('o'));
        System.out.println(str23.lastIndexOf('o', 5));

        System.out.println();

        System.out.println("7. Modifying Strings\n");

        // substring() method example

        System.out.println("substring() method example");

        String str24 = "Hello World";
        System.out.println(str24.substring(6));
        System.out.println(str24.substring(0, 5));

        System.out.println();

        // concat method example

        System.out.println("concat() method example");

        String str25 = "Hello";
        String str26 = "World";
        System.out.println(str25.concat(str26));

        System.out.println();

        // replace() method example

        System.out.println("replace() method example");

        String str27 = "Hello World";
        System.out.println(str27.replace('l', 'p'));
        System.out.println(str27.replace("Hello", "Hi"));

        System.out.println();

        // trim() method example

        System.out.println("trim() method example");

        String str28 = "   Hello World   ";
        System.out.println(str28.trim());

        System.out.println();

        // Data conversion using valueOf() method
        System.out.println("8.Data conversion using valueOf() method\n");
        int num2 = 123;
        String str29 = String.valueOf(num2);
        System.out.println(str29);

        System.out.println();

        // Changing the case of characters within a string
        System.out.println("9.Changing the case of characters within a string\n");
        String str30 = "Hello World";
        System.out.println(str30.toUpperCase());
        System.out.println(str30.toLowerCase());

        System.out.println("");

        System.out.println("10.String Buffer Class\n");

        // String Buffer Constructors
        StringBuffer sb1 = new StringBuffer();
        StringBuffer sb2 = new StringBuffer(50);
        StringBuffer sb3 = new StringBuffer("Hello World");
        System.out.println(sb1.capacity());
        System.out.println(sb2.capacity());
        System.out.println(sb3.capacity());

        System.out.println();

        // length() and capacity() method example

        System.out.println("Length and Capacity");

        StringBuffer sb4 = new StringBuffer("Hello World");
        System.out.println(sb4.length());
        System.out.println(sb4.capacity());

        System.out.println();

        // ensureCapacity() method example

        System.out.println("ensureCapacity() method");

        StringBuffer sb5 = new StringBuffer();
        System.out.println(sb5.capacity());
        sb5.ensureCapacity(50);
        System.out.println(sb5.capacity());

        System.out.println();

        // setLength() method example

        System.out.println("setLength() method");

        StringBuffer sb6 = new StringBuffer("Hello World");
        System.out.println(sb6.length());
        sb6.setLength(5);
        System.out.println(sb6.length());

        System.out.println();

        // charsAt() and setCharAt() method example

        System.out.println("charAt() and setCharAt() method");

        StringBuffer sb7 = new StringBuffer("Hello World");
        System.out.println(sb7.charAt(0));
        sb7.setCharAt(0, 'M');
        System.out.println(sb7.charAt(0));

        System.out.println();

        // getChars() method example

        System.out.println("getChars() method");

        StringBuffer sb8 = new StringBuffer("Hello World");
        char[] ch3 = new char[10];
        sb8.getChars(0, 5, ch3, 0);
        System.out.println(ch3);

        System.out.println();

        // append() method example

        System.out.println("append() method");

        StringBuffer sb9 = new StringBuffer("Hello");
        sb9.append(" World");
        System.out.println(sb9);

        System.out.println();

        // insert() method example

        System.out.println("insert() method");

        StringBuffer sb10 = new StringBuffer("Hello World");
        sb10.insert(5, " ");
        System.out.println(sb10);

        System.out.println();

        // reverse() method example

        System.out.println("reverse() method");

        StringBuffer sb11 = new StringBuffer("Hello World");
        sb11.reverse();
        System.out.println(sb11);

        System.out.println();

        // delete() and deleteCharAt() method example

        System.out.println("delete() and deleteCharAt() method");

        StringBuffer sb12 = new StringBuffer("Hello World");
        sb12.delete(5, 11);
        System.out.println(sb12);
        sb12.deleteCharAt(0);
        System.out.println(sb12);

        System.out.println();

        // replace() method example

        System.out.println("replace() method");

        StringBuffer sb13 = new StringBuffer("Hello World");
        sb13.replace(5, 11, " ");
        System.out.println(sb13);

        System.out.println();

        // substring() method example

        System.out.println("substring() method");

        StringBuffer sb14 = new StringBuffer("Hello World");
        System.out.println(sb14.substring(6));

        System.out.println();
    }
}