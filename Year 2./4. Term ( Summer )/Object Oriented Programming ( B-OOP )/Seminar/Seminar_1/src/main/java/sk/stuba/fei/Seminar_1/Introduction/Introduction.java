package sk.stuba.fei.Seminar_1.Introduction;

import org.apache.commons.cli.*;

public class Introduction {
    private static CommandLineParser parser = new BasicParser();
    private static Options options = new Options();
    public static void main(String[] args) {
        try {
            parseArgumentValue(args);
        } catch (ParseException e) {
            printParseException(e);
        }
    }
    private static void parseArgumentValue(String[] args) throws
            ParseException {
        CommandLine commandLine = parseCommands(args);
        System.out.println("a=" + commandLine.getOptionValue("a"));
    }
    private static CommandLine parseCommands(String[] args) throws
            ParseException {
        options.addOption("a", true, "an argument");
        return parser.parse(options, args);
    }
    private static void printParseException(ParseException e) {
        System.out.println(e.getMessage());
        System.out.println("Usage: java -jar -a <value>");
    }
}
