import { DiagramMetadata, FlowchartDiagram } from "./documents";

export function spreadSheetDiagramPrinter(
  diagram: FlowchartDiagram,
  targetFilename: string,
  info: DiagramMetadata
) {
  if (!targetFilename.endsWith(".xls")) {
    targetFilename += ".xls";
  }
  console.info(`Printing Excel to file ${targetFilename}`);
  return diagram!
    .flowchartDataAsSpreadsheet()
    .copyFile(info.fullFilename, targetFilename, true);
}
