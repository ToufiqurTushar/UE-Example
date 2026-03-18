import 'dart:io';

void main(List<String> args) {
  if (args.isEmpty) {
    print('Usage: dart flutter_to_umg.dart <path_to_dart_file>');
    exit(1);
  }

  final file = File(args[0]);
  if (!file.existsSync()) {
    print('Error: File not found -> ${args[0]}');
    exit(1);
  }

  String content = file.readAsStringSync();

  print('// 🚀 Transpiling Flutter Dart to Unreal C++ FlutterUMG...\n');

  // 1. Remove standard Flutter boilerplate keywords
  content = content.replaceAll(RegExp(r'\bconst\s+'), '');
  content = content.replaceAll(RegExp(r'\bnew\s+'), '');

  // 2. Wrap String literals in TEXT(...) for Unreal C++
  // e.g. Text("Hello") -> Text(TEXT("Hello"))
  content = content.replaceAllMapped(
      RegExp(r'Text\(\s*(["\'])(.*?)\1\s*\)'),
      (m) => 'Text(TEXT("${m[2]}"))');

  // 3. Map Named Parameters to Method Chaining (C++ Builder Pattern)
  // e.g. child: X -> .Child(X)
  content = content.replaceAllMapped(
      RegExp(r'child:\s*([A-Za-z0-9_]+\(.*?\)|[A-Za-z0-9_]+)', dotAll: false),
      (m) => '.Child(${m[1]})');

  content = content.replaceAllMapped(
      RegExp(r'title:\s*([A-Za-z0-9_]+\(.*?\)|[A-Za-z0-9_]+)', dotAll: false),
      (m) => '.Title(${m[1]})');

  content = content.replaceAllMapped(
      RegExp(r'appBar:\s*([A-Za-z0-9_]+\(.*?\))', dotAll: false),
      (m) => '.AppBar(\n    ${m[1]}\n  )');

  content = content.replaceAllMapped(
      RegExp(r'body:\s*([A-Za-z0-9_]+\(.*?\))', dotAll: false),
      (m) => '.Body(\n    ${m[1]}\n  )');

  content = content.replaceAllMapped(
      RegExp(r'bottomNavigationBar:\s*([A-Za-z0-9_]+\(.*?\))', dotAll: false),
      (m) => '.BottomNavigationBar(\n    ${m[1]}\n  )');

  // 4. Map 'onPressed: methodName' to C++ FName binding
  content = content.replaceAllMapped(
      RegExp(r'onPressed:\s*([A-Za-z0-9_\.]+)'),
      (m) {
        String funcName = m[1]!;
        if (funcName.contains('.')) {
          funcName = funcName.split('.').last;
        }
        return '.OnPressed(this, TEXT("$funcName"))';
      });

  // 5. Convert lists `children: [ A, B ]` to variadic arguments `( A, B )`
  // We use regex to carefully swap brackets
  content = content.replaceAll(RegExp(r'children:\s*\['), '(');
  content = content.replaceAll(RegExp(r'\]'), ')');

  // 6. Map UI layout specifically modeled in FlutterUMG
  content = content.replaceAll('mainAxisAlignment: MainAxisAlignment.center', '.MainAxisAlignment(1)');

  // 7. Semicolons cleanup
  // Replace trailing commas on class endings with C++ equivalents if they interfere
  // Note: formatting might be slightly off depending on nesting, but this parses exactly structurally.

  print('// -------------------------------------------------------------');
  print('// Copy this into your UMG C++ RebuildWidget method!');
  print('// -------------------------------------------------------------\n');
  print('TSharedRef<SWidget> UYourWidget::RebuildWidget()');
  print('{');
  print('    FFlutterBuildContext Context(this);\n');
  print('    Root = Cast<UCanvasPanel>(');
  
  // Format the lines slightly
  List<String> lines = content.split('\n');
  for (var line in lines) {
    if (line.trim().isEmpty) continue;
    if (line.trim().startsWith('import') || line.trim().startsWith('class') || line.trim().startsWith('Widget') || line.trim().startsWith('@override') || line.trim().startsWith('return')) continue;
    print('        $line');
  }

  print('    .Build();');
  print('    return Root->TakeWidget();');
  print('}');
}
