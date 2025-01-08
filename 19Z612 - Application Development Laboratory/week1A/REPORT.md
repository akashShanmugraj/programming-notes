# Week 1 Report: Basics of HTML

## 1. Basics of HTML, Tags, Attributes

HTML (HyperText Markup Language) is the standard language for creating web pages. It describes the structure of a web page using markup. HTML elements are represented by tags, and attributes provide additional information about elements.

### Document Tags
Document tags define the structure of an HTML document.

#### Example:
```html
<!DOCTYPE html>
<html>
<head>
    <title>Document Title</title>
</head>
<body>
    <h1>Hello, World!</h1>
</body>
</html>
```

#### Executed Output:
```
Document Title (displayed in the browser tab)
Hello, World! (displayed in the body of the page)
```

### Grouping Tags
Grouping tags are used to group content together.

#### Example:
```html
<div>
    <p>This is a paragraph inside a div.</p>
</div>
```

#### Executed Output:
```
This is a paragraph inside a div.
```

### Head Tags
Head tags contain meta-information about the document.

#### Example:
```html
<head>
    <title>Page Title</title>
    <meta charset="UTF-8">
</head>
```

#### Executed Output:
```
Page Title (displayed in the browser tab)
```

### Body Tags
Body tags contain the content of the HTML document.

#### Example:
```html
<body>
    <h1>Main Heading</h1>
    <p>This is a paragraph.</p>
</body>
```

#### Executed Output:
```
Main Heading
This is a paragraph.
```

### Text-level Flow Tags
Text-level flow tags are used to format text.

#### Example:
```html
<p>This is <strong>bold</strong> and this is <em>italic</em>.</p>
```

#### Executed Output:
```
This is bold and this is italic.
```

### Ordered Lists
Ordered lists display items in a numbered format.

#### Example:
```html
<ol>
    <li>First item</li>
    <li>Second item</li>
    <li>Third item</li>
</ol>
```

#### Executed Output:
```
1. First item
2. Second item
3. Third item
```

### Unordered Lists
Unordered lists display items with bullet points.

#### Example:
```html
<ul>
    <li>First item</li>
    <li>Second item</li>
    <li>Third item</li>
</ul>
```

#### Executed Output:
```
• First item
• Second item
• Third item
```

### Definition Lists
Definition lists display terms and their definitions.

#### Example:
```html
<dl>
    <dt>HTML</dt>
    <dd>HyperText Markup Language</dd>
    <dt>CSS</dt>
    <dd>Cascading Style Sheets</dd>
</dl>
```

#### Executed Output:
```
HTML
    HyperText Markup Language
CSS
    Cascading Style Sheets
```

### Table Tags
Table tags are used to create tables.

#### Example:
```html
<table>
    <tr>
        <th>Header 1</th>
        <th>Header 2</th>
    </tr>
    <tr>
        <td>Data 1</td>
        <td>Data 2</td>
    </tr>
</table>
```

#### Executed Output:

<table>
    <tr>
        <th>Header 1</th>
        <th>Header 2</th>
    </tr>
    <tr>
        <td>Data 1</td>
        <td>Data 2</td>
    </tr>
</table>

### Table Borders
